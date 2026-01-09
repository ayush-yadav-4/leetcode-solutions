class Solution {

    boolean isPalindrome(String str, int l, int r) {
        while (l < r) {
            if (str.charAt(l) != str.charAt(r)) return false;
            l++; r--;
        }
        return true;
    }

    int helper(String str, int idx, int[] dp) {
        if (idx == str.length()) return 0;

        if (dp[idx] != -1) return dp[idx];

        int ans = Integer.MAX_VALUE;

        for (int i = idx; i < str.length(); i++) {
            if (isPalindrome(str, idx, i)) {
                ans = Math.min(ans, 1 + helper(str, i + 1, dp));
            }
        }

        return dp[idx] = ans;
    }

    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return helper(s, 0, dp) - 1;
    }
}
