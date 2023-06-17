class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char>st;
        int i = 1;
        st.push(s[0]);
        string ans = "";
        while(i<n and st.size())
        {
            if(st.size() == 1 and i!=n-1 and s[i] == ')')
            {
                st.pop();
                st.push(s[i+1]);
                i++;
            }
            else
            {
                if(s[i] == '(') st.push(s[i]);
                else if(s[i] == ')') st.pop();
                ans += s[i];
            }
            i++;
        }
        ans.pop_back();
        return ans;
    }
};