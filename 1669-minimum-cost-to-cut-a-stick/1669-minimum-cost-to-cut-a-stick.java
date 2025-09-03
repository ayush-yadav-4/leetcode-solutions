class Solution {
    public int helper(int[] cuts, int i, int j, int[][] dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = Integer.MAX_VALUE;
        for (int idx = i; idx <= j; idx++) {
            int cost = cuts[j + 1] - cuts[i - 1] 
                        + helper(cuts, i, idx - 1, dp) 
                        + helper(cuts, idx + 1, j, dp);
            mini = Math.min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    public int minCost(int n, int[] cuts) {
        int m = cuts.length;
        int[] newCuts = new int[m + 2];
        for (int i = 0; i < m; i++) newCuts[i + 1] = cuts[i];
        newCuts[0] = 0;
        newCuts[m + 1] = n;
        Arrays.sort(newCuts);

        int[][] dp = new int[m + 2][m + 2];
        for (int[] row : dp) Arrays.fill(row, -1);

        return helper(newCuts, 1, m, dp);
    }
}
