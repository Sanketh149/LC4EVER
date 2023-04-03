class Solution {
    static bool comp(pair<int,int> &p1, pair<int,int> &p2)
    {
        return p1.second > p2.second;
    }
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        vector<pair<int,int>>v;
        for(auto it:nums) mp[it]++;
        int maxi = -1e9;
        for(auto it:mp)
            {v.push_back({it.first, it.second});
            maxi = max(maxi, it.second);}
        sort(v.begin(), v.end(), comp);
        vector<vector<int>>res(maxi);
        int curr = 0;
        for(int i = 0;i<v.size();i++)
        {
            int now = 0;
            while(now < v[i].second)
            {
                res[curr].push_back(v[i].first);
                curr++;
                if(curr >= maxi) curr = 0;
                now++;
            }
        }
        return res;
    }
};