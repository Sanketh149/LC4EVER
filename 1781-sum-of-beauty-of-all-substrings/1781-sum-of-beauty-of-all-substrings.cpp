class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
                map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int mn = 500,mx = 0;
                for(auto& it:mp){
                    mn=min(mn,it.second);
                    mx=max(mx,it.second);
                }
                ans+=(mx-mn);
            }
        }
    return ans;
    }
};