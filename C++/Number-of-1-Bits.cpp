class Solution {
public:
  int hammingWeight(uint32_t n) {
    int mask1 = 0x55555555;
    int mask2 = 0x33333333;
    int mask3 = 0x0f0f0f0f;
    int mask4 = 0x00ff00ff;
    int mask5 = 0x0000ffff;
    unsigned int x = n;
    x = ((x >> 1) & mask1) + (x & mask1);
    x = ((x >> 2) & mask2) + (x & mask2);
    x = ((x >> 4) & mask3) + (x & mask3);
    x = ((x >> 8) & mask4) + (x & mask4);
    x = ((x >> 16) & mask5) + (x & mask5);
    return x;
  }
};
