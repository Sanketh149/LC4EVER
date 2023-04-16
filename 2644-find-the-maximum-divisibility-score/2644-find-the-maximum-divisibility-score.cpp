class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxi = 0, res = 0;
        sort(divisors.begin(), divisors.end());
        for(auto it:divisors)
        {
            int cnt  = 0;
            for(auto i:nums)
            {
                if(i % it == 0) cnt++;
            }
            if(cnt > maxi)
            {
                maxi = cnt;
                res = it;
            }
        }
        if(res == 0)
        {
            return divisors[0];
        }
        return res;
    }
};