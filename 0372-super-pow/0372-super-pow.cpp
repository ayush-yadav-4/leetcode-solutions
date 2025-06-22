class Solution {
public:
    const int MOD = 1337;

    // Fast power modulo
    int modPow(int a, int k) {
        a %= MOD;
        int result = 1;
        for (int i = 0; i < k; ++i) {
            result = (result * a) % MOD;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;

        // Take the last digit
        int lastDigit = b.back();
        b.pop_back();

        // a^lastDigit % MOD
        int part1 = modPow(a, lastDigit);

        // (superPow(a, rest_of_b)^10) % MOD
        int part2 = modPow(superPow(a, b), 10);

        return (part1 * part2) % MOD;
    }
};
