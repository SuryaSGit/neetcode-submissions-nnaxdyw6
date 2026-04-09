//Tweet Map stores time and tweet id for each tweet of a user
//To get news feed, if following < 10, then gets the first values of everything int
//min heap. Then pop from min heap and add the next value from that user if there is one
//Keep doing this until 10 values have been added or minheap is empty.
//If following > 10, then first add stuff into a max heap. If maxheap size is less than 10, then
//Add the most recent tweet of the current user. If it is greater than 10, then
//compare with top of max heap. If top of max heap is more recent, then do not add,
//If current is more recent than top of max heap, add current to heap and pop from maxheap.
//At the end you will have the top 10 most recent first tweets from users.
//Any tweet from other users cannot be top 10.
//Convert max heap into a min heap and repeat the same process as we did for < 10 users.

class Twitter {
public:
    int count;  
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        pair<int,int> temp;
        temp.first = count;
        temp.second = tweetId;
        count--;
        tweetMap[userId].push_back(temp);
        if (tweetMap[userId].size() > 10) {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        if(!followMap[userId].contains(userId)){
            followMap[userId].insert(userId);
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        if(followMap[userId].size() < 10){
            vector<int> result;
            for(int j : followMap[userId]){
                int temp = tweetMap[j].size()-1;
                if(temp >= 0){
                    minheap.push({tweetMap[j][temp].first,tweetMap[j][temp].second,j,temp});
                }
            }
            for(int i = 0; i < 10; i++){
                if(minheap.empty()){
                    break;
                }
                int j = minheap.top()[2];
                int ind = minheap.top()[3];
                result.push_back(minheap.top()[1]);
                minheap.pop();
                if(ind > 0){
                    minheap.push({tweetMap[j][ind-1].first,tweetMap[j][ind-1].second,j,ind-1});
                }
            }
            return result;
        }
        else{
            vector<int> result;
            priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> maxheap;
            for(int j : followMap[userId]){
                if(maxheap.size() <= 10){
                    int temp = tweetMap[j].size()-1;
                    if(temp >= 0){
                        maxheap.push({tweetMap[j][temp].first,tweetMap[j][temp].second,j,temp});
                    }
                }
                else{
                    int temp = tweetMap[j].size()-1;
                    if(temp >= 0){
                        if(tweetMap[j][temp].first < maxheap.top()[0]){
                            maxheap.push({tweetMap[j][temp].first,tweetMap[j][temp].second,j,temp});
                            maxheap.pop();
                        }
                    }
                    
                }
            }
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
            for(int i = 0; i < maxheap.size(); i++){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            for(int i = 0; i < 10; i++){
                if(minheap.empty()){
                    break;
                }
                int j = minheap.top()[2];
                int ind = minheap.top()[3];
                result.push_back(minheap.top()[1]);
                minheap.pop();
                if(ind > 0){
                    minheap.push({tweetMap[j][ind-1].first,tweetMap[j][ind-1].second,j,ind-1});
                }
            }
            return result;
        }
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
