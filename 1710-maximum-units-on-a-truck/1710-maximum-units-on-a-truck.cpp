class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0;
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b){
            return a[1]>b[1];
        });
        for(auto it:boxTypes)
        {
            int toTake = min(it[0], truckSize);
            units += toTake*it[1];
            truckSize -= toTake;
            if(truckSize == 0)  break;
        }
        return units;
    }
};