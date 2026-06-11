class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;

        while (left < right) {
            while (!isValid(s[left]) && left < right) ++left;
            while (!isValid(s[right]) && left < right) --right;

            if (tolower(s[left]) != tolower(s[right])) return false;
            ++left;
            --right;
        }

        return true;
    }

    bool isValid(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
};
