class Solution {
private:
    int validRange;
    unordered_map<int, int> mapping;
    mt19937 rng{random_device{}()}; // faster and better random generator
    uniform_int_distribution<int> dist;

public:
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());
        validRange = n - blacklist.size();

        // Initialize dist for values in valid range
        dist = uniform_int_distribution<int>(0, validRange - 1);

        // Fill mapping
        int last = n - 1;
        for (int b : blacklist) {
            if (b < validRange) {
                // Find a valid last index to map to
                while (blackSet.count(last)) {
                    --last;
                }
                mapping[b] = last;
                --last;
            }
        }
    }

    int pick() {
        int x = dist(rng); // pick a number in valid range
        if (mapping.count(x)) {
            return mapping[x];
        }
        return x;
    }
};
