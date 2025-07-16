class Solution {
public:
    const int MOD = 1e9 + 7;

    long long sumFromTo(long long high, long long low) {
        return (high - low + 1) * (high + low) / 2;
    }

    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend()); // sort descending
        inventory.push_back(0); // Sentinel value

        long long res = 0;
        int n = inventory.size();

        for (int i = 0; i < n - 1 && orders > 0; i++) {
            long long count = (i + 1);
            long long curr = inventory[i], next = inventory[i + 1];
            long long diff = curr - next;

            long long total = count * diff;

            if (orders >= total) {
                // sell all from curr down to next+1
                res += count * sumFromTo(curr, next + 1);
                orders -= total;
            } else {
                // sell only part of it
                long long full = orders / count;
                long long remainder = orders % count;
                res += count * sumFromTo(curr, curr - full + 1);
                res += remainder * (curr - full);
                orders = 0;
            }

            res %= MOD;
        }

        return res;
    }
};
