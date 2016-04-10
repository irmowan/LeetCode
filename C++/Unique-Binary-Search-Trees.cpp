class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1,0);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int s = 0;
            for (int j = 0; j <i; ++j)
                s += f[j]*f[i-1-j];
            f[i] = s;
        }
        return f[n];
    }
};
