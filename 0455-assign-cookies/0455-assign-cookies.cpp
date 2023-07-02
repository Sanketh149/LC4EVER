class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int p1 = 0, p2 = 0, n1 = g.size(), n2 = s.size();
        while(p1<n1 and p2<n2)
        {
            if(s[p2] >= g[p1])
            {
                cnt++;
                p2++;
                p1++;
            }
            else{
                p2++;
            }
        }
        return cnt;
    }
};