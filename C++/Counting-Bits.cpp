class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> results;
        results.push_back(0);
        while (results.size() <= num) {
            vector<int> tmp(results);
            for (int i = 0; i < tmp.size(); ++i) {
                tmp[i]++;
                results.push_back(tmp[i]);
            }
        }
        results.resize(num + 1);
        return results;
    }
};
