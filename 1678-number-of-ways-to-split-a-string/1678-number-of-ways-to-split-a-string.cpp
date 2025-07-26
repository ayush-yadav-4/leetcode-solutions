class Solution {
public:
    int numWays(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int totalOnes = count(s.begin(), s.end(), '1');
        
        // Case 1: all 0s
        if (totalOnes == 0) {
            long long ways = ((long long)(n - 1) * (n - 2) / 2) % MOD;
            return (int)ways;
        }

        // Case 2: totalOnes not divisible by 3
        if (totalOnes % 3 != 0) return 0;
        
        // Case 3: count splits at target and 2*target
        int target = totalOnes / 3;
        long long count1 = 0, count2 = 0;
        int ones = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ++ones;
            if (ones == target) ++count1;
            else if (ones == 2 * target) ++count2;
        }

        return (count1 * count2) % MOD;
    }
};
