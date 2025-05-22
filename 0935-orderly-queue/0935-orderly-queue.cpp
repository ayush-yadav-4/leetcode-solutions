class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string result = s;
            for (int i = 1; i < s.size(); ++i) {
                string rotated = s.substr(i) + s.substr(0, i);
                result = min(result, rotated);
            }
            return result;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};
