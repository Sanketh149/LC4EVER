class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size(),i = 0;
        if(n == 1) return false;
        while(i<n)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
                st.push(s[i]);
            else{
                auto curr = s[i];
                if(st.empty()) return false;
                auto top = st.top();
                st.pop();
                if(curr == ')' and top != '(') return false;
                else if(curr == '}' and top != '{') return false;
                else if(curr == ']' and top != '[') return false;
            }
            i++;
        }
        return st.empty();
    }
};