class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        ll l = min(a, b);
        ll r = (ll)n * l;
        ll lcm = (ll)(a * b) / gcd(a, b);

        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (mid / a + mid / b - mid / lcm < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l % MOD;
    }
};
