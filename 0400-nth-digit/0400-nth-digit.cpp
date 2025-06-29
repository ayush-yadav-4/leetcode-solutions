class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;       // digit length
        long long count = 9;     // numbers with 'len' digits
        long long start = 1;     // starting number of 'len' digits

        // Step 1: Find the range where the n-th digit lies
        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Find the exact number that contains the n-th digit
        start += (n - 1) / len; // index into the block
        string s = to_string(start);

        // Step 3: Return the digit from that number
        return s[(n - 1) % len] - '0';
    }
};
