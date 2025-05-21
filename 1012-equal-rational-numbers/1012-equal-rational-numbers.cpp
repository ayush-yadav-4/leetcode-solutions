class Solution {
public:
    using ll = long long;

    pair<ll, ll> toFraction(const string& s) {
        size_t point = s.find('.');
        size_t leftParen = s.find('(');
        
        string intPart = point != string::npos ? s.substr(0, point) : s;
        string nonRep = (point != string::npos) ? s.substr(point + 1, leftParen - point - 1) : "";
        string rep = (leftParen != string::npos) ? s.substr(leftParen + 1, s.length() - leftParen - 2) : "";

        ll integer = stoll(intPart.empty() ? "0" : intPart);
        ll nonRepeat = nonRep.empty() ? 0 : stoll(nonRep);
        ll repeat = rep.empty() ? 0 : stoll(rep);

        ll base1 = pow(10, nonRep.length()); // 10^len(nonRep)
        ll base2 = rep.empty() ? 1 : (pow(10, rep.length()) - 1); // 10^len(rep) - 1

        ll denom = base1 * base2;
        ll num = integer * denom + nonRepeat * base2 + repeat;

        if (rep.empty()) denom = base1; // No repeating: use base1 only
        if (nonRep.empty()) num = integer * denom + repeat; // Only repeating
        if (nonRep.empty() && rep.empty()) num = integer * denom;

        ll g = gcd(num, denom);
        return {num / g, denom / g};
    }

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool isRationalEqual(string s, string t) {
        return toFraction(s) == toFraction(t);
    }
};
