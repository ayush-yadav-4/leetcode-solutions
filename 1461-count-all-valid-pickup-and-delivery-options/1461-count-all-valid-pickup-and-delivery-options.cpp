class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        long long mod = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            res = res * i % mod;           // Multiply by i (factorial part)
            res = res * (2 * i - 1) % mod; // Multiply by (2i - 1)
        }
        
        return res;
    }
};
