class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n, vector<int>(n, 1e9));
        for(auto it:edges)
        {
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }
        for(int i = 0;i<n;i++)  
            adj[i][i] = 0;
        vector<vector<int>>dist(adj);
        for(int k = 0;k<n;k++)
            for(int i = 0;i<n;i++)
                for(int j = 0;j<n;j++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        vector<int>res(n, 0);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                if(dist[j][i] <= distanceThreshold)
                    res[i]++;
        int mini = 1e9;
        int idx = -1;
        for(int i = 0;i<n;i++)
        {
            if(mini >= res[i])
            {
                mini = res[i];
                idx = i;
            }
        }
        return idx;
    }
};