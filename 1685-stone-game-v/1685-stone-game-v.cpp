class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        
        // Build prefix sum
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + stoneValue[i];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        function<int(int, int)> dfs = [&](int l, int r) -> int {
            if (l == r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            
            int maxScore = 0;
            for (int i = l; i < r; ++i) {
                int leftSum = prefix[i + 1] - prefix[l];
                int rightSum = prefix[r + 1] - prefix[i + 1];
                
                if (leftSum < rightSum)
                    maxScore = max(maxScore, leftSum + dfs(l, i));
                else if (leftSum > rightSum)
                    maxScore = max(maxScore, rightSum + dfs(i + 1, r));
                else
                    maxScore = max(maxScore, leftSum + max(dfs(l, i), dfs(i + 1, r)));
            }
            return dp[l][r] = maxScore;
        };
        
        return dfs(0, n - 1);
    }
};
