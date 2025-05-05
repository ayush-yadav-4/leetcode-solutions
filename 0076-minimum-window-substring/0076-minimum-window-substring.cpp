class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;  // Number of chars that meet the required count
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            char c = s[right];
            right++;
            // If it's a required character, update the window count
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // Try to shrink the window from the left
            while (valid == need.size()) {
                // Update the minimum window
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

