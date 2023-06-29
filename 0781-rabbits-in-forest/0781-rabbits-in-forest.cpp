class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int res = 0;
        unordered_map<int,int>mp;
        for(auto it:answers)
        {
            if(++mp[it] == 1) res += (it+1);
            if(mp[it] == it+1) mp[it] = 0;
        }
        return res;
    }
};