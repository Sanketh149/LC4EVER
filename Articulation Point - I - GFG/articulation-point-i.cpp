//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int timer = 1;
    void dfs(int node, int parent, int tin[], int low[], vector<int> &vis, vector<int>adj[], vector<int> &mark)
    {
        vis[node] = 1;
        low[node] = tin[node] = timer++;
        int child = 0;
        for(auto it:adj[node])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it, node, tin, low, vis, adj, mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] and parent != -1) //should go beyond and not till there 
                    mark[node] = 1;
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]); // it may be an articulation point
            }
        }
        if(child > 1 and parent == -1) mark[node] = 1;
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int>vis(n, 0);
        int low[n];
        int tin[n];
        vector<int>mark(n, 0);
        vector<int>points;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, tin, low, vis, adj, mark);
            }
        }
        for(int i = 0;i<n;i++)
            if(mark[i]) points.push_back(i);
        if(points.size()) return points;
        return {-1};
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends