class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>incomingEdges(n, 0);
        for(auto it:edges)
        {
            int src = it[0], dest = it[1];
            incomingEdges[dest]++;
        }
        vector<int>res;
        for(int i = 0;i<n;i++)
            if(incomingEdges[i] == 0) 
                res.push_back(i);
        return res;
    }
};