class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0, l = 0;

        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;

            // Shrink the window from the left until all frequencies <= k
            while (freq[nums[i]] > k) {
                freq[nums[l]]--;
                l++;
            }

            // Update the maximum subarray length
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
