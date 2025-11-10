class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Work with absolute values
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        // Calculate the quotient
        long long ans = 0;
        while (n >= d) {
            long long temp = d, count = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            n -= temp;
            ans += count;
        }

        // Apply the sign
        ans = isNegative ? -ans : ans;

        // Clamp the result within the 32-bit signed integer range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
};