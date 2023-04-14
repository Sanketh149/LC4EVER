class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>rearrangedArray(n, 0);
        int negidx = 1, posidx = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] < 0)
            {
                rearrangedArray[negidx] = nums[i];
                negidx += 2;
            }
            else {
                rearrangedArray[posidx] = nums[i];
                posidx += 2;
            }
        }
        return rearrangedArray;
    }
};