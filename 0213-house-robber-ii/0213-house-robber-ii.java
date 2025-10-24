import java.util.*;

class Solution {
    int helper(int[] nums, int idx, int[] dp) {
        if (idx >= nums.length) return 0;
        if (dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + helper(nums, idx + 2, dp);
        int notPick = helper(nums, idx + 1, dp);
        return dp[idx] = Math.max(pick, notPick);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];

        // Case 1: Rob houses 0 to n-2
        int[] case1Arr = Arrays.copyOfRange(nums, 0, n - 1);
        int[] dp1 = new int[case1Arr.length];
        Arrays.fill(dp1, -1);
        int case1 = helper(case1Arr, 0, dp1);

        // Case 2: Rob houses 1 to n-1
        int[] case2Arr = Arrays.copyOfRange(nums, 1, n);
        int[] dp2 = new int[case2Arr.length];
        Arrays.fill(dp2, -1);
        int case2 = helper(case2Arr, 0, dp2);

        return Math.max(case1, case2);
    }
}
