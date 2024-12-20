class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
 int n = digits.size();
        
        // Traverse the digits array from the last digit to the first
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // Increment the current digit and return
                digits[i]++;
                return digits;
            }
            // Set the current digit to 0 if it's 9
            digits[i] = 0;
        }
        
        // If all digits are 9, prepend a 1
        digits.insert(digits.begin(), 1);
        return digits;    }
};