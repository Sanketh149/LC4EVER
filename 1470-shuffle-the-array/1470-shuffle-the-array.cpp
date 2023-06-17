class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
         for(int i=n;i<2*n;i++)
        {
            int scndNum = nums[i]<<10;
            nums[i-n] |= scndNum;
        }
        int allOnes = (1<<10) - 1;
        for(int i = n-1;i>=0;i--)
        {
            int yi = nums[i] >> 10;
            int xi = nums[i] & allOnes;
            nums[2*i] = xi;
            nums[2*i+1] = yi;
        }
        return nums;
    }
};