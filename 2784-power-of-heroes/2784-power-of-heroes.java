class Solution {
    static final int MOD = 1_000_000_007;

    public int sumOfPower(int[] nums) {
        Arrays.sort(nums);
        long ans = 0, prefix = 0;

        for (int num : nums) {
            long dp = (num + prefix) % MOD;
            long contribution = (1L * num * num % MOD) * dp % MOD;
            ans = (ans + contribution) % MOD;
            prefix = (prefix + dp) % MOD;
        }
        return (int) ans;
    }
}
