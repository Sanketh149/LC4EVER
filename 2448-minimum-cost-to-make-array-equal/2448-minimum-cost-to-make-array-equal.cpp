using ll = long long int;
class Solution {
public:
    ll rec(vector<pair<int,int>> &v, int median)
    {
        ll sum = 0;
        for(int i = 0;i<v.size();i++)
        {
            sum += 1L*abs(v[i].first - median) * v[i].second;
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
        return rec(v, median);
    }
};