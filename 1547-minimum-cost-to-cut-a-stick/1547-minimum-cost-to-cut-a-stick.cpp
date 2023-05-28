class Solution {
public:
    int dp[103][103];
    Solution()
    {
        memset(dp,-1,sizeof(dp));
    }
    int solve(int start,int end,vector<int> &cuts)
    {
        if(end-start == 1)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans = INT_MAX;
        for(int i=start+1;i<end;i++)
        {
            int temp = (cuts[end] - cuts[start])+solve(start,i,cuts) + solve(i,end,cuts);
            ans = min(ans,temp);
        }
       return dp[start][end] = ans;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        //sort the cuts
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(0,cuts.size()-1,cuts);
    }
};