#include <set>
#include <map>
#include <vector>

class Twitter {
   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        feed.push_back(std::make_pair(userId, tweetId));
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> news_feed;
        for (int i = feed.size() - 1; i >= 0 && news_feed.size() < 10; --i) {
            if (feed.at(i).first == userId ||
                following[userId].count(feed.at(i).first)) {
                news_feed.push_back(feed.at(i).second);
            }
        }
        return news_feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

   private:
    std::vector<std::pair<int, int>> feed;
    std::map<int, std::set<int>> following;
};