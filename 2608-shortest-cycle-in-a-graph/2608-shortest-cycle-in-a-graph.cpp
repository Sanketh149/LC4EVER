class Solution {
public:
    bool dfs(int src, vector<int> adj[], int vis[], int par)
    {
        vis[src] = 1;
        for(auto next: adj[src])
        {
            if(!vis[next])
            {
                if(dfs(next, adj, vis, src)) 
                    return true;
            }
            else if(par != next)
                return true;
        }
        return false;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans = INT_MAX;
        vector<vector<int>>gr(n);
        for(auto it:edges)
        {
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {

            vector<int> dist(n, (int)(1e9));

            vector<int> vis(n, -1);

            dist[i] = 0;
            queue<int> q;

            q.push(i);

            while (!q.empty()) {

                int x = q.front();
                q.pop();

                for (int child : gr[x]) {

                    if (dist[child] == (int)(1e9)) {

                        dist[child] = 1 + dist[x];

                        vis[child] = x;

                        q.push(child);
                    }

                    else if (vis[x] != child and vis[child] != x)
                        ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
 
    if (ans == INT_MAX)
        return -1;
     else
        return ans;
    }
};