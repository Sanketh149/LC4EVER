class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = 0, ele2 = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for(auto it:nums)
        {
            if(cnt1 == 0 and it != ele2)
            {
                cnt1 = 1;
                ele1 = it;
            }
            else if(cnt2 == 0 and it != ele1)
            {
                cnt2 = 1;
                ele2 = it;
            }
            else if(it == ele1) cnt1++;
            else if(it == ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>eles;
        cnt1 = 0;
        cnt2 = 0;
        for(auto it:nums)
        {
            if(ele1 == it) cnt1++;
            else if(ele2 == it)  cnt2++;
        }
        if(cnt1 > (n/3)) eles.push_back(ele1);
        if(cnt2 > (n/3)) eles.push_back(ele2);
        return eles;
    }
};