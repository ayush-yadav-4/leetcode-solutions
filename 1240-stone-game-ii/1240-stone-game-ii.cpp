class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];

        // Create suffix sum array for fast calculation of remaining stones
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Memoization table: dp[i][M] = max stones starting from i with M
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        function<int(int, int)> dfs = [&](int i, int M) -> int {
            if (i >= n) return 0;

            if (dp[i][M] != -1) return dp[i][M];

            int maxStones = 0;

            for (int x = 1; x <= 2 * M && i + x <= n; x++) {
                // Total stones remaining - stones opponent can take
                maxStones = max(maxStones, suffixSum[i] - dfs(i + x, max(M, x)));
            }

            return dp[i][M] = maxStones;
        };

        return dfs(0, 1); // Start from index 0, M = 1
    }
};
