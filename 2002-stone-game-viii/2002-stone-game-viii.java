class Solution {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;
        
        // Step 1: prefix sums
        int[] prefix = new int[n];
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Step 2: dp from right to left
        int dp = prefix[n - 1];  // base case
        for (int i = n - 2; i >= 1; i--) {
            dp = Math.max(dp, prefix[i] - dp);
        }

        return dp;
    }
}
