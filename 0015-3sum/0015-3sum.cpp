class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i =0;i<n;i++)
        {
            if(i>0 and nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum > 0) k--;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    int c1 = nums[j], c2 = nums[k];
                    while(j<k and c1 == nums[j]) j++;
                    while(j<k and c2 == nums[k]) k--;
                }
            }
        }
        return res;
    }
};