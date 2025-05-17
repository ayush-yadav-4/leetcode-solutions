class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        // Case 1: XOR is 0 initially -> Alice wins immediately
        // Case 2: XOR is not 0, but length is even -> Alice can force a win
        return xorSum == 0 || nums.size() % 2 == 0;
    }
};
