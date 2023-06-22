using ll = long long int;
class Solution {
public:
    ll rec(vector<int> &nums, vector<int> &cost, int median)
    {
        ll sum = 0;
        for(int i = 0;i<cost.size();i++)
        {
            sum += 1L*abs(nums[i] - median) * cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll n = nums.size(), sum = 0;
        ll median = 0, res = rec(nums, cost, 1);
        ll l = 0, r = 1e6;
        while(l<r)
        {
            ll mid = (l+(r-l)/2);
            ll y1 = rec(nums, cost, mid), y2 = rec(nums, cost, mid+1);
            res = min(y1, y2);
            if(y1<y2)
                r = mid;
            else l = mid+1;
        }
        return res;
    }
};