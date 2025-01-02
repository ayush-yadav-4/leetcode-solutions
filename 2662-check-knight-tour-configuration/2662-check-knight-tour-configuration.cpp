class Solution {
public:
    // Directions for all possible knight moves
    vector<pair<int, int>> directions = {
        {-2, +1}, {-2, -1}, {+2, +1}, {+2, -1},
        {-1, +2}, {+1, +2}, {-1, -2}, {+1, -2}
    };

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // The knight's tour must start at grid[0][0] == 0
        if (grid[0][0] != 0) {
            return false;
        }

        // Current position of the knight
        int row = 0, col = 0;

        // Iterate through all numbers from 1 to n*n - 1
        for (int next = 1; next < n * n; next++) {
            bool found = false;

            // Check all possible knight moves
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                // Check if the new position is within bounds and matches the next number
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == next) {
                    row = newRow;
                    col = newCol;
                    found = true;
                    break;
                }
            }

            // If no valid move is found, the grid is invalid
            if (!found) {
                return false;
            }
        }

        // If all numbers are visited in the correct order, the grid is valid
        return true;
    }
};
