class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int row, int col) {
        // Collect all values in the 3x3 square
        vector<int> vals;
        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                int val = grid[i][j];
                if (val < 1 || val > 9) return false; // Must be 1-9
                vals.push_back(val);
            }
        }

        // Check if all values are unique
        vector<bool> seen(10, false);
        for (int val : vals) {
            if (seen[val]) return false;
            seen[val] = true;
        }

        // Check row sums
        for (int i = 0; i < 3; ++i) {
            int sum = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if (sum != 15) return false;
        }

        // Check column sums
        for (int j = 0; j < 3; ++j) {
            int sum = grid[row][col + j] + grid[row + 1][col + j] + grid[row + 2][col + j];
            if (sum != 15) return false;
        }

        // Check diagonal sums
        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        return diag1 == 15 && diag2 == 15;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        // Iterate over all possible 3x3 subgrids
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
