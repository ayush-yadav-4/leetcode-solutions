class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        int x = n + 1;  // we use n+1 to make bounds inclusive in digit DP
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());

        int len = digits.size();
        int total = 0;

        // Count numbers with length < len
        for (int i = 1; i < len; ++i) {
            total += 9 * perm(9, i - 1);
        }

        // Count numbers with length == len
        unordered_set<int> used;
        for (int i = 0; i < len; ++i) {
            for (int d = (i == 0 ? 1 : 0); d < digits[i]; ++d) {
                if (used.count(d)) continue;
                total += perm(9 - i, len - i - 1);
            }
            if (used.count(digits[i])) break;
            used.insert(digits[i]);
        }

        return n - total;  // total = count of unique digit numbers
    }

    // permutation function: P(m, n) = m * (m - 1) * ... * (m - n + 1)
    int perm(int m, int n) {
        int res = 1;
        for (int i = 0; i < n; ++i) {
            res *= (m - i);
        }
        return res;
    }
};
