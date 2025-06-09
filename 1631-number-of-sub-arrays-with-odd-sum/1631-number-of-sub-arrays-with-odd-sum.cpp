class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int odd = 0, even = 1; // prefix sum = 0 is even
        int result = 0, prefix = 0;

        for (int num : arr) {
            prefix += num;
            if (prefix % 2 == 0) {
                result = (result + odd) % MOD;
                even++;
            } else {
                result = (result + even) % MOD;
                odd++;
            }
        }

        return result;
    }
};
