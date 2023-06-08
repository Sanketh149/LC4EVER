class Solution {
public:
    int getCount(string &it)
    {
        sort(it.begin(), it.end());
        auto ch = it[0];
        int cnt = 0;
        int i = 1;
        while(i<it.size() and ch == it[i])
        {
            cnt++;
            i++;
        }
        return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>res;
        vector<int>counts;
        int n = words.size();
        for(auto &it:words)
        {
            counts.push_back(getCount(it));
        }
        sort(counts.begin(), counts.end());
        for(auto &it:queries)
        {
            int cnt = getCount(it);
            int leng = n - (upper_bound(counts.begin(), counts.end(), cnt) - counts.begin());
            res.push_back(leng);
        }
        return res;
    }
};