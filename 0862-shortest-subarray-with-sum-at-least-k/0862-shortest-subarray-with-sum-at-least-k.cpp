class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix[n];
        prefix[0]=nums[0];
        for (int i = 1; i<n; i++)
            prefix[i] = prefix[i-1] + nums[i];

        int length = n+1;
        deque<int> dq;
        for(int i=0; i<n; i++){
            if(prefix[i]>=k){
                length = min(length,i+1);
            }
            while(!dq.empty() && prefix[i]<=prefix[dq.back()]){
                dq.pop_back();
            }
            while(!dq.empty() && prefix[i]>=prefix[dq.front()]+k){
                length = min(length,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return length == n+1?-1:length;
    }
};