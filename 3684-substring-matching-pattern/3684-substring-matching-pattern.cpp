class Solution {
public:
    bool hasMatch(string s, string p) {
         size_t pos = p.find('*');
        if (pos == string::npos) return s.find(p) != string::npos;

        string prefix = p.substr(0, pos);
        string suffix = p.substr(pos + 1);

        // Check if prefix and suffix exist in correct order
        size_t start = s.find(prefix);
        if (start == string::npos) return false;

        size_t end = s.find(suffix, start + prefix.size());
        return suffix.empty() || (end != string::npos);
    }
};