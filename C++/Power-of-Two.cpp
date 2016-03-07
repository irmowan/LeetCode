class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if ((n & (n-1)) == 0)
            return true;
        else return false;
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.isPowerOfTwo(66));
    printf("%d\n", sol.isPowerOfTwo(64));
}
