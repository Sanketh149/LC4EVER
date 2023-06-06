int mod = 1e9+7;
using ll = long long;
ll dp[25][235][2];
class Solution {
public:
bool check(ll sum, int mini, int maxi)
{
    return sum>=mini && sum<=maxi;
}
    
int G(string number, int mini, int maxi, ll pos = 0, ll sum = 0, ll tight = 1)
{
	if(pos == number.size()) 
	{
		return check(sum, mini, maxi);
	}
	else if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
	else if(tight == 1)
	{
		ll res = 0;
		for(int i = 0;i<=number[pos]-'0';i++)
		{
			if(i == number[pos] - '0')
				res += G(number, mini, maxi, pos+1, sum+i, 1)%mod;
			else 
				res += G(number, mini, maxi, pos+1, sum+i, 0)%mod;
		}
		return dp[pos][sum][tight] = res%mod;
	}
	else
	{
		ll res = 0;
		for(int i = 0;i<=9;i++)
		{
			res += G(number, mini, maxi, pos+1, sum+i, 0)%mod;
		}
		return dp[pos][sum][tight] = res%mod;
	}
}
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        ll ans1 = G(num2, min_sum, max_sum); 
        memset(dp, -1, sizeof(dp));
        int n = num1.size();
        int p = n-1;
        //Getting num1 - 1 as a string 
        while(num1[p]=='0') p--; 
        num1[p++]--;
        while(p<n) num1[p++] = '9';
        ll ans2 = G(num1, min_sum, max_sum);
        int res = (ans1-ans2+mod)%mod;
        return res;
    }
};