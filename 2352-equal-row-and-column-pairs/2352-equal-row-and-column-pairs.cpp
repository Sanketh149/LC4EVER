class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        // storing row into first map
        map<vector<int>,int>mp;
            for(int i=0;i<n;i++){
                mp[grid[i]]++;
            }

        // storing counlmn into map
        map<vector<int>,int>mp2;
            for(int j=0;j<n;j++){
                vector<int>tmp;
                for(int i=0;i<n;i++){
                    tmp.push_back(grid[i][j]);
                }
                mp2[tmp]++;
            }
        int ans = 0;
        //counting number of row and col having equl value
        for(auto &it:mp){
            if(mp2.find(it.first)!=mp2.end()){
                ans+=(it.second)*mp2[it.first];
            }
        }
        return ans;
    }
};