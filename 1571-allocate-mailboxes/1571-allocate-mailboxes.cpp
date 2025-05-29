class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        
        // Precompute cost[i][j]: minimum distance to place 1 mailbox for houses[i..j]
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int median = houses[(i + j) / 2];
                for (int m = i; m <= j; ++m) {
                    cost[i][j] += abs(houses[m] - median);
                }
            }
        }

        // DP with memoization
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));

        function<int(int, int)> dp = [&](int i, int kLeft) -> int {
            if (kLeft == 0 && i == n) return 0;
            if (kLeft == 0 || i == n) return 1e9; // invalid
            if (memo[i][kLeft] != -1) return memo[i][kLeft];

            int ans = INT_MAX;
            for (int j = i; j < n; ++j) {
                ans = min(ans, cost[i][j] + dp(j + 1, kLeft - 1));
            }
            return memo[i][kLeft] = ans;
        };

        return dp(0, k);
    }
};
