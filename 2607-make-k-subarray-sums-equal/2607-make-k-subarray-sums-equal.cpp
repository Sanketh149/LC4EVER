class Solution {
public:
    long long makeSubKSumEqual(vector<int>& nums, int k) {
        int n = nums.size();
        k = __gcd(n, k); // every kth element now should be equal (array is also circular)
        long long operations = 0;
        for(int i = 0;i<k;i++)
        {
            vector<int>temp;
            for(int j = i;j<n;j+=k) temp.push_back(nums[j]);
            sort(temp.begin(), temp.end());
            int median = temp[temp.size()/2];
            for(auto it:temp)
                operations += abs(it-median);
        }
        return operations;
    }
};