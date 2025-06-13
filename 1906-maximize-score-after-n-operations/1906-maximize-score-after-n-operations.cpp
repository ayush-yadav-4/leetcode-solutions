class Solution {
public:
    int n;
    int dp[1 << 14]; // since max nums.size() = 14
    vector<int> memoGCD;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int helper(vector<int>& nums, int mask, int pairsPicked) {
        if (mask == (1 << nums.size()) - 1) {
            return 0; // all numbers used
        }
        if (dp[mask] != -1) return dp[mask];

        int maxScore = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mask & (1 << i)) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (mask & (1 << j)) continue;

                int newMask = mask | (1 << i) | (1 << j);
                int currGCD = gcd(nums[i], nums[j]);
                int currScore = (pairsPicked + 1) * currGCD;

                int remainingScore = helper(nums, newMask, pairsPicked + 1);
                maxScore = max(maxScore, currScore + remainingScore);
            }
        }
        return dp[mask] = maxScore;
    }

    int maxScore(vector<int>& nums) {
        n = nums.size() / 2;
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0);
    }
};
