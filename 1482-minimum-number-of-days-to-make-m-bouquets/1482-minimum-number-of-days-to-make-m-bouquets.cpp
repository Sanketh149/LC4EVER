class Solution {
public:
    bool isPossible(vector<int> &nums, int day, int m, int k)
    {
        int cnt = 0;
        int totalBouquets = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] <= day)
            {
                cnt++;
            }
            else{
                totalBouquets += (cnt/k);
                cnt = 0;
            }
        }
        totalBouquets += (cnt/k);
        return totalBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1ll*m*k;
        if(val > n) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            if(isPossible(bloomDay, mid, m, k))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};