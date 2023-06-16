//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>v(128, 0);
        int l = 0, r = 0, mini = 1e9, beg = 0, counter = p.size(), n = s.size();
        for(auto it:p) v[it]++;
        while(r<n)
        {
            if(v[s[r++]]-- > 0) counter--;
            while(counter == 0)
            {
                if(mini > (r-l))
                {
                    mini = r-l;
                    beg = l;
                }
                if(v[s[l++]]++ == 0) counter++;
            }
        }
        return mini == 1e9?"-1":s.substr(beg, mini);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends