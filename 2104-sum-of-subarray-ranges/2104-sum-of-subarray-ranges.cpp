class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMin(n, -1), leftMax(n, -1), rightMin(n, n), rightMax(n, n);
        stack<int>s;
        for(int i = 0;i<n;i++)
        {
            while(s.size() and nums[s.top()] >= nums[i]) s.pop();
            if(s.size()) leftMin[i] = s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = 0;i<n;i++)
        {
            while(s.size() and nums[s.top()] <= nums[i]) s.pop();
            if(s.size()) leftMax[i] = s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(s.size() and nums[s.top()] > nums[i]) s.pop();
            if(s.size()) rightMin[i] = s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(s.size() and nums[s.top()] < nums[i]) s.pop();
            if(s.size()) rightMax[i] = s.top();
            s.push(i);
        }
        long long res = 0;
        for(int i = 0;i<n;i++)
        {
            long long leftmini = i - leftMin[i];
            long long rightmini = rightMin[i] - i;
            long long leftmaxi = i - leftMax[i];
            long long rightmaxi = rightMax[i] - i;
            res += 1L*(rightmaxi*leftmaxi - rightmini*leftmini)*nums[i];
        }
        return res;
    }
};