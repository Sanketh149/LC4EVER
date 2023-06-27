//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
    public: int getMax(int num) {
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

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        Trie *root = new Trie();
        for(int i = 0;i<n;i++) root->insert(arr[i]);
        int maxNum = 0;
        for(int i = 0;i<n;i++)
            maxNum = max(maxNum, root->getMax(arr[i]));
        return maxNum;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends