class Solution {
public:
    double dfs(string start, string end, unordered_set<string> &s, unordered_map<string, unordered_map<string,double>> &mp)
    {
        if(mp[start].find(end) != mp[start].end()) return mp[start][end];
        for(auto it:mp[start])
        {
            if(s.find(it.first) == s.end())
            {
                s.insert(it.first);
                double next = dfs(it.first, end, s, mp);
                if(next) return next*it.second;
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string,double>>mp;
        vector<double>res;
        int n = values.size();
        for(int i = 0;i<n;i++)
        {
            mp[equations[i][0]].insert({equations[i][1], values[i]});
            mp[equations[i][1]].insert({equations[i][0], 1/values[i]});   
        }
        for(auto it:queries)
        {
            unordered_set<string>s;
            double curr = dfs(it[0], it[1], s, mp);
            if(curr) res.push_back(curr);
            else res.push_back(-1);
        }
        return res;
    }
};