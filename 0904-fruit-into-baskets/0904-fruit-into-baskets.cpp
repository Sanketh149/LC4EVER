class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n<=2) return n;
        unordered_map<int,int>mp;
        int l = 0, maxi = 0, len = 0;
        for(int r=0;r<n;r++)
        {
            mp[fruits[r]]++;
            len++;
            while(mp.size() > 2)
            {
                int leftFruit = fruits[l];
                mp[leftFruit]--;
                len--;
                l++;
                if(mp[leftFruit] == 0) mp.erase(leftFruit);
            }
            maxi = max(maxi, len);
        }
        return maxi;
    }
};