class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;
        
        // Make 'a' as large as possible
        char toReplaceMax = ' ';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax != ' ') {
            for (char& c : a) {
                if (c == toReplaceMax) c = '9';
            }
        }
        
        // Make 'b' as small as possible
        char toReplaceMin = ' ';
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char& c : b) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin != ' ') {
                for (int i = 1; i < b.size(); ++i) {
                    if (b[i] == toReplaceMin) b[i] = '0';
                }
            }
        }
        
        return stoi(a) - stoi(b);
    }
};
