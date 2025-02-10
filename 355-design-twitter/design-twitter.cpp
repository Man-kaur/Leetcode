class Twitter {
    unordered_map<int, unordered_set<int> > following; // user_id -> people he follows
    unordered_map<int, vector<pair<int, int>> > tweets; // user_id -> {time, tweet_id}
    int timestamp;
public:
    Twitter() {
        timestamp = 0;        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // maxheap {timestamp, tweetId}
        vector<int> feed;

        // self 
        for(const auto& tweet : tweets[userId]) pq.push(tweet);

        // following
        for(const auto& user_id : following[userId]) {
            for (const auto& tweet : tweets[user_id]) {
                pq.push(tweet);
            }
        }

        for(int i = 0; i < 10 && !pq.empty(); i++) {
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