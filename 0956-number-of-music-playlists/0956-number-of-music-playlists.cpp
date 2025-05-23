class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Add a new song
                dp[i][j] += dp[i - 1][j - 1] * (n - j + 1);
                dp[i][j] %= MOD;

                // Replay an old song
                if (j > k) {
                    dp[i][j] += dp[i - 1][j] * (j - k);
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[goal][n];
    }
};
