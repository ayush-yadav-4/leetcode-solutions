class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndexMap;
        modIndexMap[0] = -1;  // Important: handles case when prefix sum itself is divisible by k
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            
            // Handle k != 0 to avoid division by zero
            if (k != 0) {
                prefixSum %= k;
            }
            
            if (modIndexMap.find(prefixSum) != modIndexMap.end()) {
                if (i - modIndexMap[prefixSum] >= 2) {
                    return true;
                }
            } else {
                modIndexMap[prefixSum] = i; // store only first occurrence
            }
        }
        
        return false;
    }
};
