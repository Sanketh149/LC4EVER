class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = 1e9, min2 = 1e9;
        int max1 = -1e9, max2 = -1e9, max3 = -1e9;
        for(auto it:nums)
        {
            if(it <= min1)
            {
                min2 = min1;
                min1 = it;
            }
            else if(min2>=it)
            {
                min2 = it;
            }
            if(it >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = it;
            }
            else if(it >= max2)
            {
                max3 = max2;
                max2 = it;
            }
            else if(it >= max3)
            {
                max3 = it;
            }
        }
        return max(max1*max2*max3, min1*min2*max1);
    }
};