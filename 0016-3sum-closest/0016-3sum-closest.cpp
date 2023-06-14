class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0, mini = 1e9;
        for(int i = 0;i<n;i++)
        {
            if(i>0 and nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < mini){
                    mini = abs(sum - target);
                    res = sum;
                }
                if(sum > target) k--;
                else if(sum < target) j++;
                else{
                    res = sum;
                    mini = 0;
                    int curr1 = nums[j], curr2 = nums[k];
                    while(j<k and nums[j] == curr1) j++;
                    while(j<k and nums[k] == curr2) k--;
                }
            }
        }
        return res;
    }
};