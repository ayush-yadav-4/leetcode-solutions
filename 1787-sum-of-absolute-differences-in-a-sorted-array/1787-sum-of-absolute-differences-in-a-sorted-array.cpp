class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        // Build prefix sum
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            int left = i == 0 ? 0 : i * nums[i] - prefixSum[i - 1];
            int right = (prefixSum[n - 1] - prefixSum[i]) - (n - i - 1) * nums[i];
            result[i] = left + right;
        }

        return result;
    }
};
