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
        ll median = 0, total = 0;
        vector<pair<int,int>>v;
        for(int i = 0;i<n;i++)
            v.push_back({nums[i], cost[i]});
        
        sort(v.begin(), v.end());
        for(int i = 0;i<n;i++)
            sum += v[i].second;
        int i = 0;
        while(i<n and total<(sum+1)/2)
        {
            total += v[i].second;
            median = v[i].first;
            i++;
        }
        return rec(nums, cost, median);
    }
};