class DisjointSet {
    vector<int> rank, parent, size; 
public: 
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int>mp;
        DisjointSet dsu(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()) mp[mail] = i;
                else
                {
                    dsu.unionByRank(i, mp[mail]);
                }
            }
        }
        vector<string>mailNodes[n];
        for(auto it:mp)
        {
            string mail = it.first;
            int node = dsu.findUPar(it.second);
            mailNodes[node].push_back(mail);
        }
        vector<vector<string>>res;
        int  i = 0;
        for(int i = 0;i<n;i++)
        {
            auto it = mailNodes[i];
            sort(it.begin(), it.end());
            if(it.size())
            {   
                it.insert(it.begin(), accounts[i][0]);
                res.push_back(it);
            }
        }
        return res;
    }
};