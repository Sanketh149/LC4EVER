class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        vector<int>res;
        for(int i = 0;i<n;i++)
        {
            while(dq.size() and nums[dq.back()] < nums[i]) dq.pop_back();
            while(dq.size() and dq.front() <= (i-k)) dq.pop_front();
            dq.push_back(i);
            if(i >= k-1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};