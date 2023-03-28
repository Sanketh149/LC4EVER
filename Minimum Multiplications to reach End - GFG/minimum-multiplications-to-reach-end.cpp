//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& nums, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({0, start});
        int mod = 1e5;
        vector<int>dist(mod, 1e9);
        dist[start] = 0;
        while(q.size())
        {
            int steps = q.front().first, node = q.front().second;
            q.pop();
            if(node == end) return steps;
            for(auto adj:nums)
            {
                int curr = (node*adj)%mod;
                if(dist[curr]>steps+1)
                {
                    dist[curr] = steps+1;
                    q.push({dist[curr], curr});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends