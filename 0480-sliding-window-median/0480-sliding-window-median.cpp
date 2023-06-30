class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>>second_half;
        set<pair<int,int>, greater<pair<int,int>>>first_half;
        int i = 0,j = 0,n = nums.size();
        vector<double>res;
        while(j<n)
        {
            first_half.insert({nums[j], j});
            second_half.insert(*first_half.begin());
            first_half.erase(first_half.begin());
            
            if(first_half.size() < second_half.size())
            {
                first_half.insert(*second_half.begin());
                second_half.erase(second_half.begin());
            }
            
            if(j - i + 1 == k)
            {
                res.push_back(k&1?(first_half.begin()->first):(double)((0ll+first_half.begin()->first+second_half.begin()->first)*0.5));
                if(first_half.count({nums[i], i})) first_half.erase({nums[i], i});
                if(second_half.count({nums[i], i})) second_half.erase({nums[i], i});
                i++;
            }
            j++;
        }
        return res;
    }
};