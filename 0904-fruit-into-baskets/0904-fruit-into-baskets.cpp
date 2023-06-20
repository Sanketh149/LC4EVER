class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n<=2) return n;
        unordered_map<int,int>mp;
        int l = 0, maxi = 0;
        for(int r=0;r<n;r++)
        {
            mp[fruits[r]]++;
            while(mp.size() > 2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) 
                    mp.erase(fruits[l]);
                l++;
            }
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};