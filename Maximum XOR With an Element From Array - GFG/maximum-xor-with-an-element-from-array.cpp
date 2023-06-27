//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


struct Node{
    Node *links[2];
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
};



class Trie {
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
    public: void insert(int num) {
            Node *curr = root;
            for(int i = 31;i>=0;i--)
            {
                int bit = (num>>i) & 1;
                if(!curr->containsKey(bit))
                {
                    curr->put(bit, new Node());
                }
                curr = curr->get(bit);
            }
        }
    public: int findMax(int num) {
            Node *curr = root;
            int maxNum = 0;
            for(int i = 31;i>=0;i--)
            {
                int bit = (num>>i)&1;
                if(curr->containsKey(1-bit))
                {
                    maxNum = maxNum | (1<<i);
                    curr = curr->get(1-bit);
                }
                else{
                    curr = curr->get(bit);
                }
            }
            return maxNum;
        }
};

class Solution {
  public:
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
        // code here
        vector<long long>ans(queries.size(), -1);
          vector < pair < int, pair < int, int >>> offlineQueries;
          sort(arr.begin(), arr.end());
          int index = 0;
          for (auto & it: queries) {
            offlineQueries.push_back({
              it[1],
              {
                it[0],
                index++
              }
            });
          }
          sort(offlineQueries.begin(), offlineQueries.end());
          int i = 0;
          int n = arr.size();
          Trie trie;
    
          for (auto & it: offlineQueries) {
            while (i < n && arr[i] <= it.first) {
              trie.insert(arr[i]);
              i++;
            }
            if (i != 0) ans[it.second.second] = trie.findMax(it.second.first);
          }
          return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        Solution obj;
        vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends