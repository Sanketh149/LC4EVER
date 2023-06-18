class Solution {
public:
    bool static comp(pair<int,char> &a, pair<int,char> &b)
    {
        return a.first > b.first;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        vector<pair<int,char>>v;
        for(auto it:s)
            mp[it]++;
        for(auto it:mp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), comp);
        string res;
        for(auto it:v)
        {
            char x = it.second;
            int freq = it.first;
            res.append(freq, x);
        }
        return res;
    }
};