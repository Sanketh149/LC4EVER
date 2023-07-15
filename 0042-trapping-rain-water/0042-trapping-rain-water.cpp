class Solution {
public:
    int trap(vector<int>& height) {
        int vol = 0;
        int n = height.size();
        int l = 0, r = n-1, leftMax = 0, rightMax = 0;
        while(l<=r)
        {
            if(height[l] <= height[r])
            {
                leftMax = max(leftMax, height[l]);
                vol += (leftMax - height[l]);
                l++;
            }
            else{
                rightMax = max(rightMax, height[r]);
                vol += (rightMax - height[r]);
                r--;
            }
        }
        return vol;
    }
};