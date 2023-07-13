class Solution {
public:
    bool isPossible(vector<int> &nums, int mid, int k, int n)
    {
        int cnt = 1, currTime = 0;
        for(int i = 0;i<n;i++)
        {
            if(currTime + nums[i] > mid)
            {
                currTime = nums[i];
                cnt++;
            }
            else currTime += nums[i];
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(isPossible(nums, mid, k, nums.size()))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};