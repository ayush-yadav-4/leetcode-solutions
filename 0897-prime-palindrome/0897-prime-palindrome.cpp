class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        int root = sqrt(n);
        for (int i = 3; i <= root; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        // Handle small known cases directly
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        // Generate only odd-length palindromes
        for (int len = 1; len < 6; ++len) { // len is the number of digits in the first half
            int start = pow(10, len - 1);
            int end = pow(10, len);
            for (int root = start; root < end; ++root) {
                string left = to_string(root);
                string right = string(left.rbegin() + 1, left.rend()); // Skip the middle digit for odd-length
                int pal = stoi(left + right);
                if (pal >= n && isPrime(pal)) return pal;
            }
        }

        // Problem guarantees a solution exists within 2e8
        return -1;
    }
};
