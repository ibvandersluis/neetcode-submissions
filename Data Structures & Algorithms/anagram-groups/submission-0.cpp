class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {{""}};
        }

        vector<vector<string>> results;

        for (const string& str : strs) {
            bool found = false;
            for (vector<string>& vec : results) {
                if (isAnagram(str, vec[0])) {
                    vec.push_back(str);
                    found = true;
                    break;
                }
            }
            if (!found) {
                results.push_back({str});
            }
        }

        return results;
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::cout << s << " | " << t << "\n";

        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;

        for (int i = 0; i < s.length(); i++) {
            freq_s[s[i]]++;
            freq_t[t[i]]++;
        }

        std::cout << "Is anagram? " << (freq_s == freq_t) << "\n";

        return freq_s == freq_t;
    }
};
