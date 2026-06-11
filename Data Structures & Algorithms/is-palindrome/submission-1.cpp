class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator l = s.begin();
        string::iterator r = s.end();

        while (l < r) {
            while (!isValidChar(*l) && l < r) {
                l++;
            }
            while (!isValidChar(*r) && l < r) {
                r--;
            }
            if (tolower(*l) != tolower(*r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool isValidChar(char c) {
        // Only return true if character is alphanumeric
        return ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
    }
};
