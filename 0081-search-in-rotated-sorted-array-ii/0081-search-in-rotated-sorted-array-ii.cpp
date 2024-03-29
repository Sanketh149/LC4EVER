class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, n = nums.size(), high = n-1;
        while(low<=high)
        {
            int mid = (low)+(high-low)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[low] and nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target and target<=nums[mid])
                    high = mid-1;
                else low = mid+1;
            }
            else
            {
                if(nums[mid]<=target and target<=nums[high])
                    low = mid+1;
                else high = mid-1;
            }
        }
        return 0;
    }
};