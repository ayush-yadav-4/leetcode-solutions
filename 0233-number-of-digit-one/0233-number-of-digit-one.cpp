class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1;
        int res = 0;
        
        while (n / digit > 0) {
            long higher = n / (digit * 10);
            long current = (n / digit) % 10;
            long lower = n % digit;
            
            if (current == 0) {
                res += higher * digit;
            } else if (current == 1) {
                res += higher * digit + (lower + 1);
            } else {
                res += (higher + 1) * digit;
            }
            
            digit *= 10;
        }
        
        return res;
    }
};
