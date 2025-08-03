class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int surface = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    // Each cube contributes 6 faces, but vertical internal faces are hidden
                    surface += grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                    
                    // Subtract shared faces with top neighbor
                    if (i > 0) {
                        surface -= 2 * min(grid[i][j], grid[i - 1][j]);
                    }

                    // Subtract shared faces with left neighbor
                    if (j > 0) {
                        surface -= 2 * min(grid[i][j], grid[i][j - 1]);
                    }
                }
            }
        }
        
        return surface;
    }
};
