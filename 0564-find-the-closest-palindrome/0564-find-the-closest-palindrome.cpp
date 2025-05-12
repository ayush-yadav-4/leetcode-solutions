class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        set<long long> candidates;

        // Edge cases: 1000...0001 -> 999...999 and 100...001
        candidates.insert((long long)pow(10, len) + 1);
        candidates.insert((long long)pow(10, len - 1) - 1);

        // Get the first half, and create 3 variations
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string palin = p;

            // Mirror left to right
            if (len % 2 == 1)
                p.pop_back();  // remove middle digit for odd lengths

            reverse(p.begin(), p.end());
            palin += p;

            candidates.insert(stoll(palin));
        }

        candidates.erase(num); // Exclude the number itself

        long long minDiff = LLONG_MAX, closest = 0;
        for (long long c : candidates) {
            long long diff = abs(c - num);
            if (diff < minDiff || (diff == minDiff && c < closest)) {
                minDiff = diff;
                closest = c;
            }
        }

        return to_string(closest);
    }
};
