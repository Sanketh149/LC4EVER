class Solution {
public:
    string frequencySort(string s) {
        vector<int>v(128, 0);
        for(auto it:s) v[it]++;
        sort(s.begin(), s.end(), [&](char &a, char &b){
            return v[a]>v[b] or (v[a] == v[b]&&a<b);
        });
        return s;
    }
};