class Solution {
public:
    char delim = 129;

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        stringstream ss;

        for (auto& str : strs) {
            ss << str.length();
            ss << delim;
            ss << str;
        }

        return ss.str();
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }

        stringstream ss(s);
        vector<string> strs;
        
        string buf;
        while (getline(ss, buf, delim)) {
            int size = stoi(buf);
            buf.resize(size);
            ss.read(&buf[0], size);
            strs.push_back(buf);
        }

        return strs;
    }
};
