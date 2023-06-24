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
    string preToPost(string pre_exp) {
        stack<string>st;
        int n = pre_exp.size();
        for(int i = n-1;i>=0;i--)
        {
            char c = pre_exp[i];
            if(!isOperator(c))
                st.push(string(1, c));
            else{
                auto s1 = st.top();
                st.pop();
                auto s2 = st.top();
                st.pop();
                string temp = s1+s2+c;
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends