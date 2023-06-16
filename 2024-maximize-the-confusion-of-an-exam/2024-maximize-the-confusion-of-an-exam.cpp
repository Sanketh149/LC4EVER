class Solution {
public:
    int rec(string s, int k, char flag)
    {
        long long int sum = 0, l = 0, r = 0, maxi = -1e9, n = s.size();
        while(r<n)
        {
            sum += (s[r] == flag);
            while(sum > k)
            {
                sum -= (s[l] == flag);
                l++;
            }
            maxi = max(maxi, (r-l+1));
            r++;
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(rec(answerKey, k, 'T'), rec(answerKey, k, 'F'));
    }
};