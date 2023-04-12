class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            int curr = nums[i];
            if(mp.find(target - curr) != mp.end()) return {i, mp[target-curr]};
            mp[curr] = i;
        }
        return {-1,-1};
    }
};