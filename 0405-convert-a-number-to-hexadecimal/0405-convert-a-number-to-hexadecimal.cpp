class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string result = "";
        unsigned int n = num; // treat as unsigned to handle negative numbers correctly
        
        while (n != 0 && result.size() < 8) {
            int last4bits = n & 0xf; // get last 4 bits
            result.push_back(hexChars[last4bits]);
            n >>= 4; // shift right by 4 bits
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
