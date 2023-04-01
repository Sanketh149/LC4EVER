//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void dfs(int i, vector<vector<int>>& adj, vector<int> &vis, stack<int> &st)
	{
	    vis[i] = 1;
	    for(auto it:adj[i])
	    {
	        if(!vis[it]) dfs(it, adj, vis, st);
	    }
	    st.push(i);
	}
	void dfs(int i, vector<vector<int>>& adj, vector<int> &vis)
	{
	    vis[i] = 1;
	    for(auto it:adj[i])
	    {
	        if(!vis[it]) dfs(it, adj, vis);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V, 0);
        stack<int>st;
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
                dfs(i, adj, vis, st);
        }
        vector<vector<int>>adjT(V);
        for(int i = 0;i<V;i++)
        {
            for(auto it:adj[i])
                adjT[it].push_back(i);
        }
        int scc = 0;
        vector<int>vis2(V, 0);
        while(st.size())
        {
            auto curr = st.top();
            st.pop();
            if(!vis2[curr])
            {
                scc++;
                dfs(curr, adjT, vis2);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends