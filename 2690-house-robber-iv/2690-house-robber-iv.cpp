class Solution {
public:
    bool canRob(vector<int>& nums, int k, int capability) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= capability) {
                count++;
                i++;  // Skip the next house
            }
            if (count >= k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canRob(nums, k, mid)) {
                answer = mid;  // Try to minimize capability
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
