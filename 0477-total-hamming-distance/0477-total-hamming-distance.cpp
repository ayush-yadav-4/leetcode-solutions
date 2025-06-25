class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        // For each bit position from 0 to 31
        for (int i = 0; i < 32; ++i) {
            int countOnes = 0;

            // Count how many numbers have the i-th bit set
            for (int num : nums) {
                if ((num >> i) & 1) {
                    countOnes++;
                }
            }

            int countZeros = n - countOnes;
            total += countOnes * countZeros;
        }

        return total;
    }
};
