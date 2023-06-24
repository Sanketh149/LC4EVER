class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int secondMaxi = -1e9;
        stack<int>s;
        for(int i = n-1;i>=0;i--)
        {
            if(secondMaxi > nums[i]) return true;
            while(s.size() and s.top()<nums[i]){
                secondMaxi = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};