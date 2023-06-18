class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size(), n = goal.size();
        if(m != n) return false;
        return (s+s).find(goal) != string::npos;
    }
};