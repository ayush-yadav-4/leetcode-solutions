class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> seen(maxVal + 1, false);
        
        for (int num : nums) {
            seen[num] = true;
        }

        int count = 0;
        
        for (int i = 1; i <= maxVal; ++i) {
            int gcdVal = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (seen[j]) {
                    gcdVal = gcd(gcdVal, j);
                    if (gcdVal == i) {
                        break; // early exit
                    }
                }
            }
            if (gcdVal == i) {
                ++count;
            }
        }
        
        return count;
    }
};
