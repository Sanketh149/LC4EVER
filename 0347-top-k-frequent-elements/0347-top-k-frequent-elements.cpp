class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        vector<vector<int>>bucket(nums.size()+1);
        for(auto it:mp)
            bucket[it.second].push_back(it.first);
        vector<int>res;
        for(int i = nums.size();i>=0;i--)
        {
            for(auto it:bucket[i])
            {
                if(k-->0) res.push_back(it);
                else break;
            }
            if(k<=0) break;
        }
        return res;
    }
};