class RandomizedSet {
private:
  vector<int> nums;
  unordered_map<int, int> m;

public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (m.find(val) != m.end())
      return false;
    nums.push_back(val);
    m[val] = nums.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (m.find(val) == m.end())
      return false;
    int last = nums.back();
    nums[m[val]] = last;
    m[last] = m[val];
    nums.pop_back();
    m.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    if (nums.size() == 0)
      return -1;
    return nums[rand() % nums.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */