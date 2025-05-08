class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Set of primes up to 20
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        int count = 0;
        for (int i = left; i <= right; ++i) {
            int setBits = __builtin_popcount(i); // GCC built-in function to count 1s
            if (primes.count(setBits)) {
                count++;
            }
        }

        return count;
    }
};
