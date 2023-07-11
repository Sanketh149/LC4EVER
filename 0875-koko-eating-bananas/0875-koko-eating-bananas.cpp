class Solution {
public:
    long long getTotalTime(vector<int> &piles, int hourly_rate)
    {
        long long total_time = 0;
        int n = piles.size();
        for(int i = 0;i<n;i++)
        {
            total_time += ceil((double)piles[i]/(double)hourly_rate);
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        int ans = 0;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            long long res = getTotalTime(piles, mid);
            if(res <= h)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};