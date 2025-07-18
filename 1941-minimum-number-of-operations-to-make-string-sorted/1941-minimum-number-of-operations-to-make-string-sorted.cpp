class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, inv;

    // Binary exponentiation
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp % 2)
                res = res * base % MOD;
            base = base * base % MOD;
            exp /= 2;
        }
        return res;
    }

    void init(int n) {
        fact.resize(n+1);
        inv.resize(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        inv[n] = modPow(fact[n], MOD - 2);  // Fermat's Little Theorem
        for (int i = n - 1; i >= 0; --i)
            inv[i] = inv[i+1] * (i+1) % MOD;
    }

    int makeStringSorted(string s) {
        int n = s.size();
        init(n);
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            for (int j = 0; j < ch; ++j) {
                if (freq[j] == 0) continue;
                freq[j]--;
                long long ways = fact[n - i - 1];
                for (int k = 0; k < 26; ++k)
                    ways = ways * inv[freq[k]] % MOD;
                res = (res + ways) % MOD;
                freq[j]++;
            }
            freq[ch]--;
        }
        return res;
    }
};
