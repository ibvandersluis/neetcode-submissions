class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        if (s == t) return s;

        unordered_map<char, int> t_count;
        for (const char c : t) {
            t_count[c]++;
        }

        cout << "T count: " << '\n';
        for (const auto& p : t_count) {
            cout << p.first << ": " << p.second << '\n';
        }
        cout << "`````````" << '\n';

        int l {0};
        string res {""};
        unordered_map<char, int> win_count {};

        for (int r = 0; r < s.length(); ++r) {
            if (t_count.find(s[r]) != t_count.end()) {
                win_count[s[r]]++;
            }
            
            while (containsAtLeast(win_count, t_count)) {
                if (res == "" || r - l + 1 < res.length()) {
                    res = s.substr(l, r - l + 1);
                }
                if (win_count.find(s[l]) != win_count.end()) {
                    win_count[s[l]]--;
                }
                l++;
            }
        }

        return res;
    }
private:
    bool containsAtLeast(unordered_map<char,int> a, unordered_map<char,int> b) {
        if (a.size() > b.size()) return false;
        for (const auto & pair : b) {
            const char key = pair.first;
            if (a.find(key) == a.end()) {
                return false;
            }
            if (a[key] < b[key]) {
                return false;
            }
        }
        return true;
    }
};
