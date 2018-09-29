// https://leetcode.com/problems/design-twitter/

bool comparator(pair<int,int>& a, pair<int,int>& b)
{
    // tweet came later is the most recent tweet -> appear in the sorted list first
    return (a.second > b.second);
}

class Twitter {
public:
    /** Initialize your data structure here. */
    
    struct Member
    {
        vector<int>memSet;
        deque<pair<int,int>>qq;
        
        Member() {}
    };
    
    unordered_map<int,Member*>hashTwitter;
    int tweet;
    
    Twitter() {
        tweet = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(hashTwitter.find(userId) == hashTwitter.end()) {
            hashTwitter[userId] = new Member();
        }
        if(hashTwitter[userId]->qq.size() == 10) {
            hashTwitter[userId]->qq.pop_back();
        }
        hashTwitter[userId]->qq.push_front(make_pair(tweetId, tweet++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        vector<pair<int,int>>manager;
        
        if(hashTwitter.find(userId) != hashTwitter.end()) {
            
            // Own Tweet
            deque<pair<int,int>> tempq = hashTwitter[userId]->qq;
            
            for(auto itr = tempq.begin(); itr != tempq.end(); itr++) {
                manager.push_back(make_pair(itr->first, itr->second));
            }
            
            // Follower's Tweet
            for(int i = 0; i < hashTwitter[userId]->memSet.size(); i++) {
                
                tempq = hashTwitter[hashTwitter[userId]->memSet[i]]->qq;
                
                for(auto itr = tempq.begin(); itr != tempq.end(); itr++) {
                    manager.push_back(make_pair(itr->first, itr->second));
                }
            }
            
            sort(manager.begin(), manager.end(), comparator);
        }
        
        vector<int>result;
        for(int i = 0; i < manager.size() && i < 10; i++) {
            result.push_back(manager[i].first);
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        
        if(followerId == followeeId) return;
        
        if(hashTwitter.find(followerId) == hashTwitter.end()) {
            hashTwitter[followerId] = new Member();
        }
        if(hashTwitter.find(followeeId) == hashTwitter.end()) {
            hashTwitter[followeeId] = new Member();
        }
        
        bool alreadyMember = false;
        for(int i = 0; i < hashTwitter[followerId]->memSet.size(); i++) {
            if(hashTwitter[followerId]->memSet[i] == followeeId) {
                alreadyMember = true;
                break;
            }
        }
        
        if(!alreadyMember)
        hashTwitter[followerId]->memSet.push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
        if(hashTwitter.find(followerId) != hashTwitter.end() && hashTwitter.find(followeeId) != hashTwitter.end()) {
            
            for(int i = 0; i < hashTwitter[followerId]->memSet.size(); i++) {
                if(hashTwitter[followerId]->memSet[i] == followeeId) {
                    hashTwitter[followerId]->memSet.erase(hashTwitter[followerId]->memSet.begin()+i);
                    break;
                }
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */