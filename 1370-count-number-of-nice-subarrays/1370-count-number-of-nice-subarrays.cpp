class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Base case: 0 odd count has occurred once

        int oddCount = 0, result = 0;

        for (int num : nums) {
            if (num % 2 != 0) oddCount++;  // Count odd numbers

            // If we've seen (oddCount - k) before, those are valid subarrays
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                result += prefixCount[oddCount - k];
            }

            // Record this prefix sum
            prefixCount[oddCount]++;
        }

        return result;
    }
};
