#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int n = s.size();
        int i = 0;

        while (i < n) {
            char c = s[i];
            long long cnt = 0;

            // count length of block of same characters
            while (i < n && s[i] == c) {
                cnt++;
                i++;
            }

            // number of substrings = cnt * (cnt + 1) / 2
            ans = (ans + (cnt * (cnt + 1) / 2) % MOD) % MOD;
        }

        return (int)ans;
    }
};
