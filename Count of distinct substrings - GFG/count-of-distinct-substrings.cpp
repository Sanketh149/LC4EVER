//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
struct Node {
  Node * links[26];

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }

  Node * get(char ch) {
    return links[ch - 'a'];
  }

  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
};
int countDistinctSubstring(string s)
{
    //Your code here
    int n =  s.size();
    Node *root = new Node();
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        Node *curr = root;
        for(int j = i;j<n;j++)
        {
          if (!curr->containsKey(s[j])) {
            curr->put(s[j], new Node());
            cnt++;
          }
          curr = curr->get(s[j]);
        }
    }
    return cnt+1;
}