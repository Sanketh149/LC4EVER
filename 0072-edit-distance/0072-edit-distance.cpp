class Solution {
public:
    int dp[501][501];
    int rec(string word1, string word2, int idx1, int idx2)
    {
        if(idx1 == 0) return idx2;
        if(idx2 == 0) return idx1;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(word1[idx1-1] == word2[idx2-1]) return dp[idx1][idx2] = rec(word1, word2, idx1-1, idx2-1);
        int insert = rec(word1, word2, idx1, idx2-1);
        int remove = rec(word1, word2, idx1-1, idx2);
        int replace = rec(word1, word2, idx1-1, idx2-1);
        return dp[idx1][idx2] = 1 + min({insert,remove,replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return rec(word1, word2, word1.size(), word2.size());
    }
};