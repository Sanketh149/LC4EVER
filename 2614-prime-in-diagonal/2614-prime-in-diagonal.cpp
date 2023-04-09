class Solution {
public:
    bool isPrime(int n){
    if (n <= 2 || n % 2 == 0) 
        return n == 2;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
    }    
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), ans = -1e9;
        for(int i = 0; i < n; i++){
        if(isPrime(nums[i][i])) ans = max(ans, nums[i][i]);
        if(isPrime(nums[i][n - i - 1])) ans = max(ans, nums[i][n - i - 1]);
      }
        return ans == -1e9?0:ans;
    }
};