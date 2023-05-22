class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(i>0 and nums[i] == nums[i-1]) continue;
            int j = i+1,k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int curr1 = nums[j], curr2 = nums[k];
                    while(j<k and nums[j] == curr1) j++;
                    while(j<k and nums[k] == curr2) k--;
                }
            }
        }
        return ans;
    }
};