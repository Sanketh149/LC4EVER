class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int N = nums.size();
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        long long int l = 0, r = 0,n = nums.size(), maxi = -1e9;
        while(r<n)
        {
            while(nums[l] + N <= nums[r]) l++;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return N - maxi;
    }
};