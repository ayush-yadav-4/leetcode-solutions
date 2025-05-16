class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        // Try every pair of numbers
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                
                vector<double> next;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) {
                        next.push_back(nums[k]);
                    }
                }

                // Try all 4 operations
                vector<double> candidates;
                candidates.push_back(nums[i] + nums[j]);
                candidates.push_back(nums[i] - nums[j]);
                candidates.push_back(nums[j] - nums[i]);
                candidates.push_back(nums[i] * nums[j]);

                if (nums[j] != 0) candidates.push_back(nums[i] / nums[j]);
                if (nums[i] != 0) candidates.push_back(nums[j] / nums[i]);

                for (double val : candidates) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }
};
