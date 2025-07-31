class Solution {
public:
    int rev(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> count;
        const int MOD = 1e9 + 7;
        long long result = 0;

        for (int num : nums) {
            int key = num - rev(num);
            result = (result + count[key]) % MOD;
            count[key]++;
        }

        return result;
    }
};
