class Solution {
public:
    bool static comp(vector<int> &eve1, vector<int> &eve2)
    {
        if(eve1[0] == eve2[0]) return eve1[1]>eve2[1];
        return eve1[0]<eve2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int n = envelopes.size();
        vector<int>lis;
        for(auto it:envelopes)
        {
            auto curr = lower_bound(lis.begin(), lis.end(), it[1]) - lis.begin();
            if(curr >=  lis.size()) lis.push_back(it[1]);
            else lis[curr] = it[1]; 
        }
        return lis.size();
    }
};