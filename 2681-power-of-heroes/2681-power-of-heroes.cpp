class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long power = 0;
        long long sum = 0;
        long long mod = 1000000007;
        for(auto num:nums)
        {
            power = (power+(num * (num+sum) % mod * num))%mod;
            sum = (sum*2 + num)%mod;
        }
        return power;
    }
};