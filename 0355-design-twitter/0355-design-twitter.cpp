class Twitter {
    private:
        unordered_map<int,set<int>>followers;
        unordered_map<int,vector<pair<int,int>>> tweets;
        long long time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(auto it = tweets[userId].begin();it != tweets[userId].end();it++)
            pq.push(*it);
        for(auto it = followers[userId].begin(); it != followers[userId].end();it++)
        {
            int user = *it;
            for(auto it2 = tweets[user].begin();it2!=tweets[user].end();it2++)
                pq.push(*it2);
        }
        while(pq.size())
        {
            res.push_back({pq.top().second});
            pq.pop();
            if(res.size() == 10)
                return res;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].find(followeeId) != followers[followerId].end())
            followers[followerId].erase(followeeId);
    }
};
