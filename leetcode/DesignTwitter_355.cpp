#include <bits/stdc++.h>
using namespace std;

class Twitter {
  struct User {
    unordered_set<int> following;
    vector<pair<int, int>> posts;
  };

  struct Tweet {
    int tweetId;
    int userId;
    ulong idx;

    bool operator()(const pair<int, Tweet> &other) { return true; }
  };

  struct comp {
    bool operator()(const pair<int, Tweet> &a, const pair<int, Tweet> &b) {
      return a.first > b.first;
    }
  };

  unordered_map<int, User> users;
  int tweetCounter;

public:
  /** Initialize your data structure here. */
  Twitter() { tweetCounter = 0; }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    users[userId].posts.emplace_back(make_pair(tweetCounter, tweetId));
    users[userId].following.insert(userId);
    tweetCounter++;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, Tweet>, vector<pair<int, Tweet>>, comp> pq;

    for (int publisher : users[userId].following) {
      if (users.find(publisher) == users.end())
        continue;

      vector<pair<int, int>> &posts = users[publisher].posts;
      pair<int, int> &lastPost = posts[posts.size() - 1];
      Tweet t{lastPost.second, publisher, posts.size() - 1};
      pq.emplace(make_pair(lastPost.first, t));
    }

    vector<int> feed;
    feed.reserve(10);

    while (!pq.empty() && feed.size() != 10) {
      pair<int, Tweet> rmTweet = pq.top();
      pq.pop();
      int tweetId = rmTweet.second.tweetId;
      int userId = rmTweet.second.userId;
      int idx = rmTweet.second.idx;
      cout << tweetId << endl;

      feed.push_back(tweetId);

      if (idx == 0)
        continue;
      pq.emplace(make_pair(users[userId].posts[idx - 1].first,
                           Tweet{tweetId, userId, idx - 1ul}));
    }
    return feed;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    users[followerId].following.insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    users[followerId].following.erase(followeeId);
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