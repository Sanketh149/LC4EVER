//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        vector<long long>dist(n, LLONG_MAX);
        vector<long long>steps(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        steps[0] = 1;
        int mod = 1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto i:roads)
        {
            adj[i[1]].push_back({i[0], i[2]});
            adj[i[0]].push_back({i[1], i[2]});
        }
        while(pq.size())
        {
            int wt = pq.top().first, node = pq.top().second;
            pq.pop();
            for(auto adjNode:adj[node])
            {
                if(dist[adjNode.first] > wt + adjNode.second)
                {
                    dist[adjNode.first] = wt + adjNode.second;
                    steps[adjNode.first] = steps[node];
                    pq.push({dist[adjNode.first], adjNode.first});
                }
                else if(dist[adjNode.first] == wt + adjNode.second)
                {
                    steps[adjNode.first] = (steps[adjNode.first]+steps[node])%mod;
                }
            }
        }
        return steps[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends