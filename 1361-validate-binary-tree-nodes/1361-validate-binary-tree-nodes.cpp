class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indeg(n, 0);
        for(int i = 0;i<n;i++)
        {
            if(leftChild[i] != -1) 
            {
                indeg[leftChild[i]]++;
                if(indeg[leftChild[i]] > 1) return false;
            }
            if(rightChild[i] != -1)
            {
                indeg[rightChild[i]]++;
                if(indeg[rightChild[i]] > 1) return false;
            }
        }
        int root = -1; 
        for(int i = 0;i<n;i++)
        {
            if(indeg[i] == 0) 
            {
                if(root == -1) 
                    root = i;
                else 
                    return false;
            }
        }
        if(root == -1) return false;
        queue<int>q;
        q.push(root);
        vector<int>vis(n, 0);
        while(q.size())
        {
            auto curr = q.front();
            q.pop();
            if(vis[curr]) 
                return false;
            vis[curr] = 1;
            if(leftChild[curr] != -1) q.push(leftChild[curr]);
            if(rightChild[curr] != -1) q.push(rightChild[curr]);
        }
        int noOfVisited = 0;
        for(auto it:vis)
            if(it == 1) noOfVisited++;
        return noOfVisited == n;
    }
};