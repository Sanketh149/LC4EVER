class Solution {
public:
    int dp[101][101];
    bool rec(int i, int j, int k, int n1, int n2, int n3, string s1, string s2, string s3)
    {
        if(i == n1 and j == n2 and k == n3) return true;
        bool curr1 = false, curr2 = false;
        if(dp[i][j] != -1) return dp[i][j];
        if(i<n1 and k<n3 and s1[i] == s3[k])
        {
            curr1 = rec(i+1,j,k+1,n1,n2,n3,s1,s2,s3);
        }
        if(j<n2 and k<n3 and s2[j] == s3[k])
        {
            curr2 = rec(i,j+1,k+1,n1,n2,n3,s1,s2,s3);
        }
        return dp[i][j] = (curr1 or curr2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return rec(0,0,0,s1.size(), s2.size(), s3.size(), s1,s2,s3);
    }
};