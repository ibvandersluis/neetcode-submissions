class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        } 
        stack<char> pile;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                pile.push(c);
            } else if (!pile.empty()) {
                switch(c) {
                    case ')':
                        if (pile.top() != '(') return false;
                        pile.pop();
                        break;
                    case '}':
                        if (pile.top() != '{') return false;
                        pile.pop();
                        break;
                    case ']':
                        if (pile.top() != '[') return false;
                        pile.pop();
                        break;
                }
            } else {
                return false;
            }
        }
        return pile.empty();
    }
};
