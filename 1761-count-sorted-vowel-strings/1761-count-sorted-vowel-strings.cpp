class Solution {
public:
    int countVowelStrings(int n) {
        // We need to compute C(n + 4, 4)
        int N = n + 4;
        int R = 4;
        long long res = 1;
        for (int i = 1; i <= R; ++i) {
            res *= N - i + 1;
            res /= i;
        }
        return res;
    }
};
