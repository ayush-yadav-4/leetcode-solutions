class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; ++i) {
            int num = i;
            bool hasDifferentDigit = false;
            bool isValid = true;
            
            while (num > 0) {
                int digit = num % 10;
                num /= 10;
                
                if (digit == 3 || digit == 4 || digit == 7) {
                    isValid = false;
                    break;
                }
                
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    hasDifferentDigit = true;
                }
            }
            
            if (isValid && hasDifferentDigit) {
                ++count;
            }
        }
        
        return count;
    }
};
