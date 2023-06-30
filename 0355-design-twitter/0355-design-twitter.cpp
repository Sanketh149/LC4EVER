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
        for(auto tweet : tweets[userId]){
            pq.push(tweet);
        }
        for(auto followee : followers[userId]){
            for(auto tweet: tweets[followee]){
                pq.push(tweet);
            }
        }
        int n = min(10, (int)pq.size());
        for(int i = 0;i<n;i++)
        {
            res.push_back({pq.top().second});
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].find(followeeId) != followers[followerId].end())
            followers[followerId].erase(followeeId);
    }
};
