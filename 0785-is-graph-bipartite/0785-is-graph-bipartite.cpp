class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &color, int currcolor)
    {
        color[node] = currcolor;
        for(auto it:graph[node])
        {
            if(color[it] == -1)
            {
                if(dfs(graph, it, color, !currcolor) == false) return false;
            }
            else if(color[it] == currcolor) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(), -1);
        for(int i = 0;i<graph.size();i++)
        {
            if(color[i] == -1)
            {
                if(dfs(graph, i, color, 0) == false) return false;
            }
        }
        return true;
    }
};