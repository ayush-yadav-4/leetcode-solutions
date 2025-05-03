class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        // remove first and last character
        string sub = ss.substr(1, ss.length() - 2);
        return sub.find(s) != string::npos;
    }
};
