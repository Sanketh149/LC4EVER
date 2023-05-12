class Solution {
public:
    long long maxPoints(vector<vector<int>>& questions, int idx, long dp[])
    {
        if(idx >= questions.size()) 
            return 0;
        if(dp[idx] != -1) return dp[idx];
        long take = questions[idx][0]+maxPoints(questions, idx+questions[idx][1]+1, dp);
        long notTake = maxPoints(questions, idx+1, dp);
        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long dp[n];
        memset(dp, -1, sizeof(dp));
        return maxPoints(questions, 0, dp);
    }
};