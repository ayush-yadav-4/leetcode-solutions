class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index_map;  // num -> last index
        for (int i = 0; i < nums.size(); ++i) {
            if (index_map.find(nums[i]) != index_map.end()) {
                if (i - index_map[nums[i]] <= k) {
                    return true;
                }
            }
            index_map[nums[i]] = i;  // update last index
        }
        return false;
    }
};
