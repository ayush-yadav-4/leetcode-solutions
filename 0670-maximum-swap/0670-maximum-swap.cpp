class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> last(10, -1);

        // Store the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }

        // Try to find the first position where a larger digit exists later
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }

        return num; // No better swap found
    }
};