class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {{""}};
        }

        unordered_map<string, vector<string>> sig_to_str;

        for (const string& str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            sig_to_str[key].push_back(str);
        }

        vector<vector<string>> results;

        for (const auto& pair : sig_to_str) {
            results.push_back(pair.second);
        }

        return results;
    }

    int* strSignature(string s) {
        int* sig = new int[26];
        
        if (s.empty()) {
            return sig;
        }

        

        return sig;
    }
};
