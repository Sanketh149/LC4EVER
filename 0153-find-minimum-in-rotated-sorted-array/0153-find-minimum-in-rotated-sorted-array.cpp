class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, n = nums.size(), high = n-1;
        int ans = 1e9;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[low] <= nums[high]) //whole search space is already sorted
            {
                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else 
            {
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};