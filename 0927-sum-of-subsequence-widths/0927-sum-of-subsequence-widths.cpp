class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> pow2(n);  // Precompute powers of 2
        pow2[0] = 1;
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long max_contrib = pow2[i];
            long long min_contrib = pow2[n - 1 - i];
            res = (res + (nums[i] * (max_contrib - min_contrib)) % MOD) % MOD;
        }

        // Ensure non-negative result
        if (res < 0) res += MOD;
        return res;
    }
};
