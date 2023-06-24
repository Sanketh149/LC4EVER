class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int>s;
        int n = nums.size();
        vector<int>nge(n, n);
        for(int i = n-1;i>=0;i--)
        {
            while(s.size() and nums[s.top()] <= nums[i]) s.pop();
            if(s.size()) nge[i] = s.top() - i;
            else nge[i] = 0;
            s.push(i);
        }
        return nge;
    }
};