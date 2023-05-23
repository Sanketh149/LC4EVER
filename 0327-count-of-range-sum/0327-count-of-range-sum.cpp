using LL = long long;
class Solution {
public:
    int merge(vector<LL> &nums, int low, int mid, int high, int lower, int upper)
    {
        LL count = 0;
        int start = mid+1, end = mid+1;
        for(int i = low;i<=mid;i++)
        {
            while(start<=high and nums[start] - nums[i] < lower) start++; //lower-bound
            while(end<=high and nums[end] - nums[i] <= upper) end++; //upper-bound
            count += (end - start);
        }
        vector<LL>temp;
        int idx = 0, left = low, right = mid+1;
        while(left <= mid and right <= high)
        {
            if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);
        copy(temp.begin(), temp.end(), nums.begin()+low);
        return count;
    }
    int mergeSort(vector<LL> &nums, int low, int high, int lower, int upper)
    {
        if(low >= high) return 0;
        int count = 0;
        int mid = (low + high)/2;
        count += mergeSort(nums, low, mid, lower, upper);
        count += mergeSort(nums , mid+1, high, lower, upper);
        count += merge(nums, low, mid, high, lower, upper);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<LL>prefix(n+1, 0);
        for(int i = 0;i<n;i++)
            prefix[i+1] = prefix[i]+nums[i];
        return mergeSort(prefix, 0, n, lower, upper);
    }
};