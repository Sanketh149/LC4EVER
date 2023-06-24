class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int>leftMin(n, 0), rightMin(n, 0);
        stack<int>s;
        for(int i = 0;i<n;i++)
        {
            while(s.size() and nums[s.top()] >= nums[i])
                s.pop();
            if(s.size() == 0) leftMin[i] = i+1;
            else leftMin[i] = i - s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(s.size() and nums[s.top()] > nums[i]) 
                s.pop();
            if(s.size() == 0) rightMin[i] = n - i;
            else rightMin[i] = s.top() - i;
            s.push(i);
        }
        for(int i =0;i<n;i++)
        {
             long long noOfSubArrays = (leftMin[i]*rightMin[i])%mod;
             long long currProd = (noOfSubArrays*nums[i])%mod;
             res = (res+currProd)%mod;
        }
        return res;
    }
};