class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int i = 0, n = s.size();
        while(i<n)
        {
            auto curr = s[i];
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')')
            {
                reverse(s.begin()+st.top()+1, s.begin()+i);
                st.pop();
            }
            i++;
        }
        string res;
        for(auto it:s) if(it != '(' and it != ')') res += it;
        return res;
    }
};