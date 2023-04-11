class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), curr = 1;
        for(int i = 0;i<n;i++)
        {
            while(i+1<n and nums[i] == nums[i+1]) {
                i++;
            }
            if(i+1 < n) nums[curr++] = nums[i+1];
        }
        return curr;
    }
};