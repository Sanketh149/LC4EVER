class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorr = 0;
        for(auto i:nums)
            xorr ^= i;
        int xor1 = 0, xor2 = 0;
        unsigned int cnt = xorr & ~(xorr-1);
        for(auto i:nums)
        {
            if(i & (cnt))
                xor1 ^= i;
            else xor2 ^= i;
        }
        return {xor1,xor2};
    }
};