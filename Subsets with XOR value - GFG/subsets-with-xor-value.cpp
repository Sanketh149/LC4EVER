//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int rec(vector<int> &nums, int n, int k, int xorr, int i)
    {
        if(i == n)
        {
            if(xorr == k) return 1;
            return 0;
        }
        int take = rec(nums, n, k, xorr^nums[i], i+1);
        int nottake = rec(nums , n, k, xorr, i+1);
        return take + nottake;
    }
    int subsetXOR(vector<int> nums, int n, int K) {
        return rec(nums, n , K, 0, 0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends