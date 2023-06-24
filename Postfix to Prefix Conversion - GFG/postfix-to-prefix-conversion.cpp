//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperator(char x)
    {
        switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
        }
        return false;
    }
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>st;
        int n = post_exp.size();
        for(int i = 0;i<n;i++)
        {
            char c = post_exp[i];
            if(!isOperator(c))
                st.push(string(1, c));
            else{
                auto s1 = st.top();
                st.pop();
                auto s2 = st.top();
                st.pop();
                string temp = c+s2+s1;
                st.push(temp);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends