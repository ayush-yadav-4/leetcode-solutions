class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<tuple<int, int, int>> stones;

        // Store each stone as a tuple of (combined value, alice value, bob value)
        for (int i = 0; i < n; ++i) {
            stones.push_back({aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]});
        }

        // Sort in descending order of combined value
        sort(stones.begin(), stones.end(), [](auto& a, auto& b) {
            return get<0>(a) > get<0>(b);
        });

        int aliceScore = 0, bobScore = 0;

        // Simulate turns
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                // Alice's turn
                aliceScore += get<1>(stones[i]);
            } else {
                // Bob's turn
                bobScore += get<2>(stones[i]);
            }
        }

        if (aliceScore > bobScore) return 1;
        if (aliceScore < bobScore) return -1;
        return 0;
    }
};
