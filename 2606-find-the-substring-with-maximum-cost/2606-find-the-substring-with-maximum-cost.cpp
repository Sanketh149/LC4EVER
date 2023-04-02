class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int cost = 0, maxCost = -1e9;
        for(auto it:s)
        {
            if(find(chars.begin(), chars.end(), it) == chars.end())
            {
                int curr = it - 96;
                cost += curr;
                if(cost < 0) {
                    cost = 0;
                }
                maxCost = max(maxCost, cost);
            }
            else {
                auto idx = find(chars.begin(), chars.end(), it) - chars.begin();
                int curr = vals[idx];
                cost += curr;
                if(cost < 0) {
                    cost = 0;
                }
                maxCost = max(maxCost, cost);
            }
        }
        return maxCost;
    }
};