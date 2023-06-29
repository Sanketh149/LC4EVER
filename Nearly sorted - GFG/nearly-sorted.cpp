//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int nums[], int num, int K){
        priority_queue<int,vector<int>, greater<int>>pq;
        for(int i = 0;i<=K;i++)
            pq.push(nums[i]);
        vector<int>res(num, -1);
        int idx = 0;
        for(int i = K+1;i<num;i++)
        {
            res[idx++] = pq.top();
            pq.pop();
            pq.push(nums[i]);
        }
        while(pq.size())
        {
            res[idx++] = pq.top();
            pq.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends