class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        map<int,int>mp;
        for(auto it:nums) mp[it]++;
        priority_queue<int,vector<int>, greater<int>>pq;
        for(auto it:mp) pq.push(it.first);
        while(pq.size())
        {
            int curr = pq.top();
            for(int i = curr;i<curr+k;i++)
            {
                if(mp[i] > 0)
                {   
                    mp[i]--;
                    if(mp[i] == 0)
                        pq.pop();
                }
                else return false;
            }
        }
        return true;
    }
};