class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            if (isPalindrome(word)) {
                return word;  // return the first palindrome found
            }
        }
        return "";  // return empty string if none found
    }
};
