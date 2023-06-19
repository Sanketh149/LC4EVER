class Solution {
public:
    vector<bool>sieve;
    int countPrimes(int n) {
        sieve.resize(n+1, true);
        for(int i = 2;i*i<=n;i++)
        {
            if(sieve[i] == true)
            {
                for(int j = i*i;j<=n;j+=i)
                {
                    sieve[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2;i<n;i++)
            if(sieve[i] == true)
                cnt++;
        return cnt;
    }
};