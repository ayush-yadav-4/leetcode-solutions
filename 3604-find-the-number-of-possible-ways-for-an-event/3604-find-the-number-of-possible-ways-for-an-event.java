class Solution {
    int MOD = 1000000007;
    public int numberOfWays(int n, int x, int y) {
        long[][] comb = new long[x + 1][x + 1];
        comb[0][0] = 1;
        for (int i = 1; i <= x; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        long[][] S = new long[n + 1][x + 1];
        S[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= Math.min(i, x); j++) {
                S[i][j] = (S[i - 1][j - 1] + (j * S[i - 1][j]) % MOD) % MOD;
            }
        }

        long[] fact = new long[x + 1];
        fact[0] = 1;
        for (int i = 1; i <= x; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long[] powY = new long[x + 1];
        powY[0] = 1;
        for (int i = 1; i <= x; i++) {
            powY[i] = (powY[i - 1] * y) % MOD;
        }

        long result = 0;
        for (int m = 1; m <= x && m <= n; m++) {
            result = (result + (((((comb[x][m] * S[n][m]) % MOD) * fact[m]) % MOD) * powY[m]) % MOD) % MOD;
        }
        return (int) result;
    }
}