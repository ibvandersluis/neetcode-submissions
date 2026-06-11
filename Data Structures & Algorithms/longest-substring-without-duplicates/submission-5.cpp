class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int l {0};
        int r {0};
        int longest {1};
        unordered_set<char> char_set;

        while (r < s.length()) {
            while (char_set.count(s[r]) && l <= r) {
                char_set.erase(s[l]);
                l++;
            }

            char_set.insert(s[r]);
            longest = max(longest, r - l + 1);
            r++;
        }
        
        return longest;
    }
};
