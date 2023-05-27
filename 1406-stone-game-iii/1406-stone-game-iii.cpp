class Solution {
public:
    vector<int>dp;
    int rec(int idx, vector<int>&stones)
    {
        int n = stones.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take1 = -1e9, take2 = -1e9, take3 = -1e9;
        if(idx+1<=n) take1 = stones[idx]-rec(idx+1,stones);
        if(idx+2<=n) take2 = stones[idx]+stones[idx+1]-rec(idx+2,stones);
        if(idx+3<=n) take3 = stones[idx]+stones[idx+1]+stones[idx+2] - rec(idx+3, stones);
        return dp[idx] = max({take1, take2, take3});
       
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size()+1, -1);
        int res = rec(0, stoneValue);
        if(res > 0) return "Alice";
        else if(0 > res) return "Bob";
        else return "Tie";
    }
};