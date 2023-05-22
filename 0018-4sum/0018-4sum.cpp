class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(i>0 and nums[i] == nums[i-1]) continue; //duplicates for i
            for(int j = i + 1;j<n;j++)
            {
                if(j != i+1 and nums[j] == nums[j-1]) continue; //duplicates for j
                int k = j+1, l = n-1;
                while(k<l)
                {
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        int curr1 = nums[k], curr2 = nums[l];
                        while(k<l and nums[k] == curr1) k++; //duplicates for k
                        while(k<l and nums[l] == curr2) l--; //duplicates for l
                    }
                }
            }
        }
        return res;
    }
};