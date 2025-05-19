class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int N = nums.size(), S = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);

        for (int num : nums) {
            // We must go in reverse to avoid using the same number twice
            for (int k = N - 1; k >= 0; --k) {
                for (int s : dp[k]) {
                    dp[k + 1].insert(s + num);
                }
            }
        }

        for (int k = 1; k < N; ++k) {
            if ((S * k) % N != 0) continue;
            int target = S * k / N;
            if (dp[k].count(target)) return true;
        }

        return false;
    }
};
