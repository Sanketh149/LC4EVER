class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int n = cards.size(), mini = 1e9;
        mp[cards[0]] = 0;
        for(int i = 1;i<n;i++)
        {
            if(mp.find(cards[i]) != mp.end())
                mini = min(mini, i - mp[cards[i]]);
            mp[cards[i]] = i;
        }
        return mini == 1e9?-1:mini+1;
    }
};