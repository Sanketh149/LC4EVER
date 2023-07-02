class Solution {
public:
    bool isvalid(string s){
        int n= s.size();
        int cnt=0;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]) cnt++;
            
        }
        if(cnt<=1) return true;
        return false;
    }
    int longestSemiRepetitiveSubstring(string s) {
        int n= s.size();
        int len=0;
        for(int i=0; i<n; i++){
            string ans="";
            for(int j=i; j<n; j++){
                ans+=s[j];
                if(isvalid(ans)){
                    len= max(len,j-i+1);
                }
                
                
            }
        }
        return len;
        
    }
};