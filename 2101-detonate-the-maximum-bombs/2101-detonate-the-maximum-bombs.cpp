class Solution {
public:
    void dfs(vector<vector<int>> &graph, int &cnt, vector<bool> &vis, int i)
    {
        vis[i] = true;
        cnt++;
        for(auto adj:graph[i])
        {
            if(!vis[adj])
                dfs(graph, cnt, vis, adj);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>graph(n);
        for(int j = 0;j<n;j++)
        {
            auto it = bombs[j];
            long long x1 = it[0], y1 = it[1], r1 = it[2];
            for(int i = 0;i<n;i++)
            {
                if(i != j)
                {
                    auto it2  = bombs[i];
                    long long x2 = it2[0] - bombs[j][0], y2 = it2[1] - bombs[j][1];
                    if(x2*x2+y2*y2<=r1*r1)
                        graph[j].push_back(i);
                }
            }
        }
        int comp = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            int curr = 0;
            vector<bool>vis(n, false);
            dfs(graph, curr, vis, i);
            comp = max(comp, curr);
        }
        return comp;
    }
};