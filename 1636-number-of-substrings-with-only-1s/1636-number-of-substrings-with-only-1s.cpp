class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int count = 0;
        
        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                // Add the number of substrings for the previous segment of ones
                result = (result + (long long)count * (count + 1) / 2) % MOD;
                count = 0;
            }
        }
        
        // Add the last segment if it ends with '1'
        result = (result + (long long)count * (count + 1) / 2) % MOD;
        
        return (int)result;
    }
};
