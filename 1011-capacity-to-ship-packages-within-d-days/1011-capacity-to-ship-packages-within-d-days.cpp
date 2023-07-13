class Solution {
public:
    bool isPossible(vector<int> &weights, int mid, int days)
    {
        int cnt = 0, currDays = 0;
        for(int i = 0;i<weights.size();i++)
        {
            if(weights[i]+cnt > mid)
            {
                currDays += 1;
                cnt = weights[i];
            }
            else{
                cnt += weights[i];
            }
        }
        return currDays+1 <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            if(isPossible(weights, mid, days))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};