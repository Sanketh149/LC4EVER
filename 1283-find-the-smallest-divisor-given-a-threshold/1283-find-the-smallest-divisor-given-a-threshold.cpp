class Solution {
public:
    bool isLessThanThreshold(vector<int> &nums, int mid,int threshold)
    {
        int cnt = 0;
        for(auto it:nums)
        {
            cnt += ceil((double)it/(double)mid);
        }
        return cnt<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            if(isLessThanThreshold(nums, mid, threshold))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};