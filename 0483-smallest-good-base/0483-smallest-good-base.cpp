class Solution {
public:
    string smallestGoodBase(string n) {
        typedef unsigned long long ull;
        ull num = stoull(n);
        
        for (int m = 64; m >= 2; --m) {
            ull left = 2, right = pow(num, 1.0 / (m - 1)) + 1;
            while (left <= right) {
                ull k = left + (right - left) / 2;
                ull sum = 1, curr = 1;
                
                for (int i = 1; i < m; ++i) {
                    if (curr > num / k) {  // Avoid overflow
                        sum = num + 1;
                        break;
                    }
                    curr *= k;
                    sum += curr;
                }
                
                if (sum == num) return to_string(k);
                else if (sum < num) left = k + 1;
                else right = k - 1;
            }
        }
        return to_string(num - 1);  // Fallback: base n-1 => 11
    }
};
