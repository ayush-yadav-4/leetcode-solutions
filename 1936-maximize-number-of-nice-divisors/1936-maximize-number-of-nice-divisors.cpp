class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }

    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3)
            return primeFactors;
        
        long long q = primeFactors / 3;
        int r = primeFactors % 3;

        if (r == 0) {
            return modPow(3, q, MOD);
        } else if (r == 1) {
            return modPow(3, q - 1, MOD) * 4 % MOD;
        } else { // r == 2
            return modPow(3, q, MOD) * 2 % MOD;
        }
    }
};
