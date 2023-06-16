using ll = long long int;
class Solution {
public:
    vector<vector<ll>>pascal;
    int mod = 1e9+7;
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascal.resize(n+1);
        for(int i = 0;i<n+1;i++)
        {
            pascal[i] = vector<ll>(i+1, 1);
            for(int j = 1;j<i;j++)
            {
                pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j])%mod;
            }
        }
        return (dfs(nums)-1)%mod;
    }
    ll dfs(vector<int> &nums)
    {
        int n = nums.size();
        if(n<3) return 1;
        vector<int>left, right;
        for(int i = 1;i<n;i++)
        {
            if(nums[0]>nums[i]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        ll a1 = dfs(left)%mod, a2 = dfs(right)%mod;
        return (a1*a2)%mod * pascal[n-1][left.size()]%mod;
    }
};