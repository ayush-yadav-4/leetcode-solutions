class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        
        string result = "";
        
        while (n != 0) {
            int remainder = n % -2;
            
            // Make remainder positive
            if (remainder < 0) {
                remainder += 2;
                n = (n - remainder) / -2;
            } else {
                n /= -2;
            }
            
            result = to_string(remainder) + result;
        }
        
        return result;
    }
};
