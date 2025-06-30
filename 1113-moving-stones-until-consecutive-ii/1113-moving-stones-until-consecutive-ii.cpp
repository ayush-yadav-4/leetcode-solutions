class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMove = max(stones[n-2] - stones[0] + 1 - (n - 1),
                          stones[n-1] - stones[1] + 1 - (n - 1));

        // Calculate min moves using sliding window
        int minMove = n;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                ++i;
            }
            int alreadyPlaced = j - i + 1;
            if (alreadyPlaced == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                // Edge case: need 2 moves, not 1
                minMove = min(minMove, 2);
            } else {
                minMove = min(minMove, n - alreadyPlaced);
            }
        }
        
        return {minMove, maxMove};
    }
};
