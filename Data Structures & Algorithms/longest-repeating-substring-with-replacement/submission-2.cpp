class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) return 0;
        unordered_map<char, int> count;
        int res {0};
        int maxf {0};
        int l {0};
        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
