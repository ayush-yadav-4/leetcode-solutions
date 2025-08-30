class Solution {
    static final int MOD = 1_000_000_007;
    static long[] fact;
    static long[] invFact;

    public int countAnagrams(String s) {
        // Precompute factorials
        int max = 100_000;
        precompute(max);

        String[] words = s.split(" ");
        long ans = 1;

        for (String word : words) {
            ans = (ans * countWord(word)) % MOD;
        }
        return (int) ans;
    }

    private long countWord(String word) {
        int n = word.length();
        int[] freq = new int[26];
        for (char c : word.toCharArray()) freq[c - 'a']++;

        long res = fact[n];
        for (int f : freq) {
            if (f > 1) {
                res = (res * invFact[f]) % MOD;
            }
        }
        return res;
    }

    private void precompute(int n) {
        if (fact != null) return; // already precomputed
        fact = new long[n + 1];
        invFact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    private long modPow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
}
