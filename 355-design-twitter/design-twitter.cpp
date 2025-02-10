class Twitter {
    unordered_map<int, set<int>> following;   // userId -> followings
    unordered_map<int , vector<pair<int,int>>> tweets;  // userId -> {time, tweetId}
    int time;
public:

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // time -> tweet
        vector<int> feed;

        for(auto &tweet : tweets[userId]){
            pq.push({tweet.first, tweet.second});
        }

        for(auto &f : following[userId]){
            for(auto &tweet : tweets[f]){
                pq.push({tweet.first, tweet.second});
            }
        }

        for(int i=0; i<10 && !pq.empty(); i++){
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */