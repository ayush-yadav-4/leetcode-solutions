class Solution {
public:
    bool isPalindrome(string s) {
      int i = 0;
        string ans;

        while (s[i] != '\0') {
            if (isalnum(s[i])) { // Check if alphanumeric
                ans += tolower(s[i]); // Convert to lowercase and append
            }
            i++; // Increment i in every iteration
        }

        string ans1 = ans;
        reverse(ans.begin(), ans.end());
        return ans1 == ans;
    }
};