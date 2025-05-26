class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 20000;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b % 2) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    void init() {
        fact.resize(MAX + 1);
        invFact.resize(MAX + 1);
        fact[0] = 1;
        for (int i = 1; i <= MAX; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[MAX] = modPow(fact[MAX], MOD - 2);
        for (int i = MAX - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int k) {
        if (n < k) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    unordered_map<int, int> primeFactorize(int k) {
        unordered_map<int, int> factors;
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                factors[i]++;
                k /= i;
            }
        }
        if (k > 1) factors[k]++;
        return factors;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        init();
        vector<int> res;
        for (auto& q : queries) {
            int n = q[0], k = q[1];
            auto factors = primeFactorize(k);
            long long ways = 1;
            for (auto& [p, e] : factors) {
                ways = ways * comb(e + n - 1, n - 1) % MOD;
            }
            res.push_back((int)ways);
        }
        return res;
    }
};
