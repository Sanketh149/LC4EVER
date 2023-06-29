//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> nums, int k)
    {
        //code here
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>pq;
        for(int i = 0;i<k;i++)
        {
            pq.push({nums[i][0],i,0});
        }
        vector<int>res;
        while(pq.size())
        {
            int val = pq.top()[0], arrNum = pq.top()[1], idx = pq.top()[2];
            pq.pop();
            res.push_back(val);
            if(idx+1<k)
            {
                pq.push({nums[arrNum][idx+1], arrNum, idx+1});
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends