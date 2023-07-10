class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1, n = nums.size();
        
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1])
                return nums[mid];
            
            if(mid&1)
            {
                if(nums[mid] == nums[mid-1])
                    low = mid+1;
                else high = mid-1;
            }
            
            else
            {
                if(nums[mid] == nums[mid+1])
                    low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};