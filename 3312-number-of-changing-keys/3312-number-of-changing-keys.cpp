class Solution {
public:
    int countKeyChanges(string s) {
          int changes = 0;
        char lastKey = tolower(s[0]);
        
        for (int i = 1; i < s.size(); i++) {
            if (tolower(s[i]) != lastKey) { 
                changes++;
                lastKey = tolower(s[i]); 
            }
        }
        return changes;
    }
};