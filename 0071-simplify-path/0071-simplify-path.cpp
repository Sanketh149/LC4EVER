class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string res;
        while(getline(ss, res, '/'))
        {
            if(res.size() == 0 or res == ".")
                continue;
            if(res == "..")
            {
                if(st.size()) st.pop();
            }
            else st.push(res);
        }
        string res2;
        while (!st.empty()) {
            res2 = "/" + st.top() + res2;
            st.pop();
        }
        return res2.empty() ? "/" : res2;
    }
};