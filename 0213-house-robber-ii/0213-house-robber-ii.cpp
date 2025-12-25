class Solution {
public:
    int helper(int idx, int start, vector<int>& nums, vector<int>& dp) {
        if (idx < start) return 0;
        if (idx == start) return nums[start];

        if (dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + helper(idx - 2, start, nums, dp);
        int notPick = helper(idx - 1, start, nums, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        vector<int> dp1(n, -1);
        int case1 = helper(n - 2, 0, nums, dp1);

        // Case 2: exclude first house
        vector<int> dp2(n, -1);
        int case2 = helper(n - 1, 1, nums, dp2);

        return max(case1, case2);
    }
};
