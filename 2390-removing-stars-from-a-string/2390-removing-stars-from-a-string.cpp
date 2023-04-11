class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto it:s)
        {
            if(it == '*' and st.size())
                st.pop();
            else st.push(it);
        }
        string removed;
        while(st.size())
        {
            removed += st.top();
            st.pop();
        }
        reverse(removed.begin(), removed.end());
        return removed;
    }
};