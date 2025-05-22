class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        int numLen = num.size();
        int dLen = digits.size();
        vector<int> dp(numLen + 1, 0);
        dp[numLen] = 1;  // base case

        // Count numbers with the same length as n
        for (int i = numLen - 1; i >= 0; --i) {
            char currentDigit = num[i];
            for (string& d : digits) {
                if (d[0] < currentDigit) {
                    dp[i] += pow(dLen, numLen - i - 1);
                } else if (d[0] == currentDigit) {
                    dp[i] += dp[i + 1];
                }
            }
        }

        // Count numbers with fewer digits than n
        int result = dp[0];
        for (int i = 1; i < numLen; ++i) {
            result += pow(dLen, i);
        }

        return result;
    }
};
