class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    int help[5] = {0,1,0,-1,0};
    bool isValid(int r, int c, int n)
    {
        return r>=0 and r<n and c>=0 and c<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet dsu(n*n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int currNode = i * n + j;
                    for(int k = 0;k<4;k++)
                    {
                        int nr = i+help[k], nc = j+help[k+1];
                        if(isValid(nr, nc, n) and grid[nr][nc] == 1)
                        {
                            int adjNode = nr*n + nc;
                            dsu.unionBySize(currNode, adjNode);
                        }
                    }
                }
            }
        }
        int maxArea = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    int currNode = i * n + j;
                    set<int>s;
                    for(int k = 0;k<4;k++)
                    {
                        int nr = i+help[k], nc = j+help[k+1];
                        if(isValid(nr, nc, n) and grid[nr][nc] == 1)
                        {
                            int adjNode = nr*n + nc;
                            if(dsu.findUPar(currNode) != dsu.findUPar(adjNode))
                            {
                                s.insert(dsu.findUPar(adjNode));
                            }
                        }
                    }
                    int area = 0;
                    for(auto it:s)
                        area += dsu.size[it];
                    maxArea = max(maxArea, area+1);
                }
            }
        } 
        for(int cellNo = 0;cellNo<n*n;cellNo++)  //for matrix with all 1's
            maxArea = max(maxArea, dsu.size[dsu.findUPar(cellNo)]);
        return maxArea;
    }
};