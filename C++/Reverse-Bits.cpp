class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int x = n;
    x = (n >> 16) | (n << 16);
    x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
    x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
    x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
    return x;
  }
};