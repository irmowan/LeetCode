class Twitter {
private:
  struct Tweet {
    int time;
    int id;
    Tweet(int time, int id) : time(time), id(id) {}
  };
  unordered_map<int, vector<Tweet>> tweets;
  unordered_map<int, unordered_set<int>> following;
  int time;

public:
  /** Initialize your data structure here. */
  Twitter() : time(0) {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(Tweet(time++, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<pair<Tweet *, Tweet *>> h;
    for (const int &u : following[userId]) {
      vector<Tweet> &t = tweets[u];
      if (t.size() > 0) {
        h.emplace_back(t.data(), t.data() + t.size() - 1);
      }
    }

    auto &t = tweets[userId];
    if (t.size() > 0) {
      h.emplace_back(t.data(), t.data() + t.size() - 1);
    }
    auto f = [](const pair<Tweet *, Tweet *> &x,
                const pair<Tweet *, Tweet *> &y) {
      return x.second->time > y.second->time;
    };
    make_heap(h.begin(), h.end(), f);
    const int nums = 10;
    vector<int> result;
    result.reserve(nums);
    for (int i = 0; i < nums && !h.empty(); ++i) {
      pop_heap(h.begin(), h.end(), f);
      pair<Tweet *, Tweet *> &next = h.back();
      result.push_back(next.second->id);
      if (next.first == next.second--)
        h.pop_back();
      else
        push_heap(h.begin(), h.end(), f);
    }
    return result;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
      following[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
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