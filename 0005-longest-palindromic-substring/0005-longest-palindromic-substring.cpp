class Solution {
public:
    string expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        string longest = "";
        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome (centered at i)
            string odd = expandAroundCenter(s, i, i);
            // Even-length palindrome (centered at i, i+1)
            string even = expandAroundCenter(s, i, i + 1);

            // Update longest palindrome found
            if (odd.size() > longest.size()) longest = odd;
            if (even.size() > longest.size()) longest = even;
        }
        return longest;
    }
};
