class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size(), n = potions.size();
        vector<int>res;
        sort(potions.begin(), potions.end());
        int maxi = potions[n-1];
        for(auto it:spells)
        {
            long long mini = ceil((1.0 * success)/it);
            auto idx = lower_bound(potions.begin(), potions.end(), mini) - potions.begin();
            res.push_back(n - idx);
        }
        return res;
    }
};