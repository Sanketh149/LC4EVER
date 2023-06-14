class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int>mp;
        for(auto it1:nums1)
            for(auto it2:nums2)
                mp[it1+it2]++;
        int count = 0;
        //key observation is that one element should be picked from all 4..
        for(auto it3:nums3) 
            for(auto it4:nums4)
                count += mp[-(it3+it4)];
        return count;
    }
};