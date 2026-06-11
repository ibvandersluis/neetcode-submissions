class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> substr_count;

        for (const char c : s1) {
            substr_count[c]++;
        }

        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            unordered_map<char, int> matcher_count;
            for (int j = 0; j < s1.length(); j++) {
                matcher_count[s2[i+j]]++;
            }
            if (substr_count == matcher_count) {
                return true;
            }
        }

        return false;
    }
};
