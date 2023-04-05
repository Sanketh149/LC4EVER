class Solution {
public:
    static bool comp(pair<string,int> &p1, pair<string, int> &p2)
    {
        if(p1.second == p2.second) return p1.first<p2.first;
        return p1.second < p2.second;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        queue<int>q;
        q.push(id);
        vector<int>vis(n, 0);
        vis[id] = 1;
        vector<string>videos;
        map<string,int>mp;
        while(q.size() and level--)
        {
            int siz = q.size();
            for(int i = 0;i<siz;i++)
            {
                int node = q.front();
                q.pop();
                for(auto it:friends[node])
                {
                   if(!vis[it])
                   {
                       vis[it] = 1;
                       q.push(it);
                   }
                }
            }
        }
        while(q.size())
        {
            int node = q.front();
            q.pop();
            for(auto curr:watchedVideos[node])
                mp[curr]++;
        }
        vector<pair<string,int>>v;
        for(auto it:mp)
            v.push_back({it.first, it.second});
        sort(v.begin(), v.end(), comp);
        for(auto it:v)
            videos.push_back(it.first);
        return videos;
    }
};