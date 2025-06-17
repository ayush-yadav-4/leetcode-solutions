class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);  // dp[i] will be the minimum number of perfect squares that sum to i
        dp[0] = 0;  // base case

        // Precompute all perfect squares less than or equal to n
        vector<int> perfectSquares;
        for (int i = 1; i * i <= n; ++i) {
            perfectSquares.push_back(i * i);
        }

        // DP iteration
        for (int i = 1; i <= n; ++i) {
            for (int square : perfectSquares) {
                if (i < square) break;
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }

        return dp[n];
    }
};
