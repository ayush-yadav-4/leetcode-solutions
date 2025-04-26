class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n);  
        dp[0] = 1;
        int m = primes.size();
        vector<int> indices(m, 0);
        vector<long long> next(m); 

        for (int i = 0; i < m; ++i) {
            next[i] = primes[i]; 
        }
        
        for (int i = 1; i < n; ++i) {
            long long min_val = *min_element(next.begin(), next.end());
            dp[i] = min_val;
            
            for (int j = 0; j < m; ++j) {
                if (next[j] == min_val) {
                    indices[j]++;
                    next[j] = dp[indices[j]] * primes[j];
                }
            }
        }
        
        return static_cast<int>(dp[n - 1]); 
    }
};