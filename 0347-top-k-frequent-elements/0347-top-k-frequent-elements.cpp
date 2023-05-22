class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(auto it:nums)
            mp[it]++;
        for(auto it:mp)
            pq.push({it.second, it.first});
        vector<int>ans;
        while(pq.size() and k--)
        {
            auto curr = pq.top();
            pq.pop();
            ans.push_back(curr.second);
        }
        return ans;
    }
};