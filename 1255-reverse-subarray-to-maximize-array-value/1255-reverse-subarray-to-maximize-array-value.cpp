class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int base = 0;

        // Compute original sum
        for (int i = 0; i < n - 1; ++i) {
            base += abs(nums[i] - nums[i + 1]);
        }

        int max_gain = 0;

        // Try reversing subarray at start or end
        for (int i = 1; i < n - 1; ++i) {
            max_gain = max(max_gain, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            max_gain = max(max_gain, abs(nums[n - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1]));
        }

        // Try all middle reversals
        int min_max = INT_MAX, max_min = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i], b = nums[i + 1];
            min_max = min(min_max, max(a, b));
            max_min = max(max_min, min(a, b));
        }

        max_gain = max(max_gain, 2 * (max_min - min_max));

        return base + max_gain;
    }
};
