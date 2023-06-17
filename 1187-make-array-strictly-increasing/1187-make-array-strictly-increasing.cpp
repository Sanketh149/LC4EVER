class Solution {
public:
    int rec(vector<int> &nums1, vector<int> &nums2, int curr, int prev, map<pair<int,int>, int> &mp)
    {
        if(curr == nums1.size()) return 0;
        if(mp.find({curr, prev}) != mp.end()) return mp[{curr,prev}];
        int pick1 = 1e9, pick2 = 1e9, notPick2 = 1e9;
        int currNo = nums1[curr];
        if(currNo <= prev) //no other option but to pick
        {
            auto nextIdx = upper_bound(nums2.begin(), nums2.end(), prev) - nums2.begin();
            if(nextIdx < nums2.size() and nums2[nextIdx] > prev)
            {
                pick1 = rec(nums1, nums2, curr+1, nums2[nextIdx], mp);
                if(pick1!=1e9)
                    pick1++;
            }
        }
        else{
            notPick2 = rec(nums1, nums2, curr+1, nums1[curr], mp);
            auto nextIdx = upper_bound(nums2.begin(), nums2.end(), prev) - nums2.begin();
            if(nextIdx < nums2.size() and nums2[nextIdx] > prev)
            {
                pick2 = rec(nums1, nums2, curr+1, nums2[nextIdx], mp);
                if(pick2!=1e9)
                    pick2++;
            }
        }
        return mp[{curr, prev}] = min({pick1, pick2, notPick2});
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        map<pair<int,int>, int>mp;
        int ans = rec(arr1, arr2, 0, -1, mp);
        return ans == 1e9?-1:ans;
    }
};