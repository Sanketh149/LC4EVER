//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> nums, int n) {
        // code here
        int xor1 = 0, xor2 = 0, xorr = 0;
        for(int i = 0;i<n;i++)
        {
            xorr ^= nums[i];
            xorr ^= (i+1);
        }
        int RMB = xorr & ~(xorr-1);
        for(int i = 0;i<n;i++)
        {
            if(nums[i] & RMB) xor1 ^= nums[i];
            else xor2 ^=  nums[i];
        }
        for(int i = 1;i<=n;i++) 
            if(i & RMB) xor1 ^= i;
            else xor2 ^= i;
        int cnt = 0;
        for(auto it:nums)
            if(it == xor1) cnt++;
        if(cnt == 2) return {xor1,xor2};
        return {xor2, xor1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends