class Solution {
public:
    string toLowerCase(string s) {
           for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A'); 
            }
        }
        return s;
    }
};