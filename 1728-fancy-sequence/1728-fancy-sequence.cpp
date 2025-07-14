class Fancy {
private:
    static const int MOD = 1e9 + 7;
    vector<int> sequence, add_snap, mult_snap;
    long long add = 0, mult = 1;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return modPow(a, MOD - 2); // Fermat's Little Theorem
    }

public:
    Fancy() {}

    void append(int val) {
        sequence.push_back(val);
        add_snap.push_back(add);
        mult_snap.push_back(mult);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mult = (mult * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= sequence.size()) return -1;

        long long val = sequence[idx];
        long long insertAdd = add_snap[idx];
        long long insertMult = mult_snap[idx];

        long long ratio = (mult * modInverse(insertMult)) % MOD;

        long long result = (val * ratio) % MOD;
        result = (result + (add - (insertAdd * ratio) % MOD + MOD) % MOD) % MOD;

        return result;
    }
};
