class Solution {
public:
    bool isMatch(string s, string p) {
        int l = s.size();
        vector <int> t(l + 1, 0);
        t[0] = 1;
        int pp = 0;
        while (pp < p.size()) {
            // Print
            for (auto i = 0; i < l + 1; ++i) cout << t[i];
            cout << endl;

            bool star = false;
            char c = p[pp];
            pp++;
            if (pp < p.size() && p[pp] == '*') {
                pp++;
                star=true;
            }
            cout << c << ' ' << star << endl;
            vector <int> tt(l + 1, 0);
            for (int i = 0; i < l + 1; ++i) {
                if (t[i] == 0) continue;
                if (star == false) {
                    if (i < l && (s[i] == c || c == '.')) tt[i + 1] = 1;
                }
                else {
                    auto k = i;
                    tt[k] = 1;
                    while (k < l && (s[k] == c || c == '.')) {
                        k++;
                        tt[k] = 1;
                    }
                }
            }
            t = tt;
        }
        // Print
        for (auto i = 0; i < l + 1; ++i) cout << t[i];
        cout << endl;

        if (t[l] == 1) return true;
        return false;
    }
};
