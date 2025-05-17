class Solution {
public:
    // Count trailing zeroes in x!
    int trailingZeroes(long long x) {
        int count = 0;
        while (x > 0) {
            x /= 5;
            count += x;
        }
        return count;
    }

    // Binary search for leftmost x such that f(x) == k
    long long findLeft(int k) {
        long long low = 0, high = 5LL * (k + 1);  // prevent overflow
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (trailingZeroes(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int preimageSizeFZF(int k) {
        return findLeft(k + 1) - findLeft(k);
    }
};
