class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 =  nums2.size();
        vector<int>res(n1, -1);
        map<int,int>mp;
        stack<int>s;
        for(int i = n2-1;i>=0;i--)
        {
            while(s.size() and s.top()<nums2[i]) s.pop();
            if(s.size() == 0) mp[nums2[i]] = -1;
            else mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for(int i = 0;i<n1;i++)
        {
            res[i] = mp[nums1[i]];
        }
        return res;
    }
};