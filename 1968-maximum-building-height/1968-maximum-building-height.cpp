class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add building 1 with height 0 (mandatory)
        restrictions.push_back({1, 0});
        
        // Sort restrictions by building index
        sort(restrictions.begin(), restrictions.end());

        // Add building n with unrestricted max height
        if (restrictions.back()[0] != n)
            restrictions.push_back({n, n - 1});
        
        int m = restrictions.size();

        // Left to right pass: apply adjacent height change rule
        for (int i = 1; i < m; ++i) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1],
                restrictions[i - 1][1] + dist);
        }

        // Right to left pass
        for (int i = m - 2; i >= 0; --i) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],
                restrictions[i + 1][1] + dist);
        }

        // Compute max peak between restricted buildings
        int maxHeight = 0;
        for (int i = 1; i < m; ++i) {
            int x1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int x2 = restrictions[i][0],     h2 = restrictions[i][1];
            int dist = x2 - x1;

            // Max peak between x1 and x2
            int peak = (h1 + h2 + dist) / 2;
            maxHeight = max(maxHeight, peak);
        }

        return maxHeight;
    }
};
