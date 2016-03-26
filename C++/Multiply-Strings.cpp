class Solution {
public:
  string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    int len = len1 + len2;
    string s = "";
    vector<int> a(len1 + len2, 0);
    for (int i = 0; i < len1; ++i)
      for (int j = 0; j < len2; ++j)
        a[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
    int temp = 0;
    for (int i = len - 1; i >= 0; --i) {
      a[i] = a[i] + temp;
      temp = a[i] / 10;
      a[i] = a[i] % 10;
    }
    for (int i = 0; i < len; ++i)
      s += a[i] + '0';
    // Move the zeros at the beginning.
    int start = 0;
    while (s[start] == '0')
      start++;
    if (start == len)
      s = "0";
    else
      s = s.substr(start, len - start);
    return s;
  }
};
