class Solution {
public:
    int helper(int idx, vector<int>& prices, int buy, vector<vector<int>>& dp) {
        if (idx == prices.size()) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        int profit;
        if (buy == 1) {
            profit = max(
                -prices[idx] + helper(idx + 1, prices, 0, dp),
                helper(idx + 1, prices, 1, dp)
            );
        } else {
            profit = max(
                prices[idx] + helper(idx + 1, prices, 1, dp),
                helper(idx + 1, prices, 0, dp)
            );
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(0, prices, 1, dp);
    }
};
