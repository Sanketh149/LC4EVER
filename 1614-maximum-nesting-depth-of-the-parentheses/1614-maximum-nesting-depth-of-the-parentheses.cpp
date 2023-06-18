class Solution {
public:
    int maxDepth(string s) {
        int maxi = -1e9, open = 0, close = 0,n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')')close++;
            maxi = max(maxi, open-close);
        }
        return maxi;
    }
};