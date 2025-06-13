class Solution {
public:
    int dp[1 << 14]; // memoization array for 2^14 states

    // Helper function to calculate GCD
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int helper(vector<int>& nums, int mask, int pairsPicked) {
        int n = nums.size();
        if (mask == (1 << n) - 1) return 0; // all numbers used
        if (dp[mask] != -1) return dp[mask];

        int maxScore = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) continue;
            for (int j = i + 1; j < n; ++j) {
                if (mask & (1 << j)) continue;

                int newMask = mask | (1 << i) | (1 << j);
                int score = (pairsPicked + 1) * gcd(nums[i], nums[j]);
                maxScore = max(maxScore, score + helper(nums, newMask, pairsPicked + 1));
            }
        }
        return dp[mask] = maxScore;
    }

    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0);
    }
};
