class Solution {
public:
    string lcp(vector<string>& strs)
    {
        sort(strs.begin(), strs.end());
        string start = strs[0];
        string end = strs[strs.size()-1];
        string res = "";
        for(int i=0;i<end.size();i++)
        {
            if(start[i] != end[i])
                break;
            res += start[i];
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        return lcp(strs);
    }
};