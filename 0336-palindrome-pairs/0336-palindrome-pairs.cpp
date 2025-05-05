class Solution {
public:
    bool isPalindrome(const string& str, int left, int right) {
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedIndex;
        vector<vector<int>> result;

        // Store reversed word -> index
        for (int i = 0; i < words.size(); ++i) {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            reversedIndex[reversed] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            string current = words[i];
            int len = current.size();

            for (int j = 0; j <= len; ++j) {
                string prefix = current.substr(0, j);
                string suffix = current.substr(j);

                // Case 1: prefix is palindrome, find reversed(suffix)
                if (isPalindrome(current, 0, j - 1)) {
                    if (reversedIndex.count(suffix) && reversedIndex[suffix] != i) {
                        result.push_back({reversedIndex[suffix], i});
                    }
                }

                // Case 2: suffix is palindrome, find reversed(prefix)
                // j != len avoids duplicates when prefix and suffix overlap fully
                if (j != len && isPalindrome(current, j, len - 1)) {
                    if (reversedIndex.count(prefix) && reversedIndex[prefix] != i) {
                        result.push_back({i, reversedIndex[prefix]});
                    }
                }
            }
        }

        return result;
    }
};
