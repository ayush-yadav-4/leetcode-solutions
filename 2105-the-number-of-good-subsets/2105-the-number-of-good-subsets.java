class Solution {
    private static final int MOD = 1_000_000_007;
    private static final int[] PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    public int numberOfGoodSubsets(int[] nums) {
        int[] freq = new int[31];
        for (int num : nums) freq[num]++;
        
        // Precompute number to bitmask mapping (only valid numbers)
        Map<Integer, Integer> numToMask = new HashMap<>();
        for (int num = 2; num <= 30; num++) {
            int mask = 0;
            int x = num;
            boolean isValid = true;
            for (int i = 0; i < PRIMES.length; i++) {
                int prime = PRIMES[i];
                int count = 0;
                while (x % prime == 0) {
                    x /= prime;
                    count++;
                }
                if (count > 1) {
                    isValid = false; // not distinct prime product
                    break;
                }
                if (count == 1) mask |= (1 << i);
            }
            if (isValid && x == 1) {
                numToMask.put(num, mask);
            }
        }

        // DP: dp[mask] = number of subsets with this product bitmask
        long[] dp = new long[1 << PRIMES.length];
        dp[0] = 1;

        for (int num = 2; num <= 30; num++) {
            if (!numToMask.containsKey(num) || freq[num] == 0) continue;
            int currMask = numToMask.get(num);
            for (int mask = (1 << PRIMES.length) - 1; mask >= 0; mask--) {
                if ((mask & currMask) == 0) { // no overlap, can be added
                    dp[mask | currMask] = (dp[mask | currMask] + dp[mask] * freq[num]) % MOD;
                }
            }
        }

        // Sum all subsets (except empty subset dp[0])
        long result = 0;
        for (int mask = 1; mask < (1 << PRIMES.length); mask++) {
            result = (result + dp[mask]) % MOD;
        }

        // Add ones: each one can be included or not => 2^count_of_1
        int countOnes = freq[1];
        long multiplier = modPow(2, countOnes, MOD);
        result = (result * multiplier) % MOD;

        return (int) result;
    }

    private long modPow(long base, int exp, int mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) != 0) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
