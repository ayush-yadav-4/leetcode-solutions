class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int x = 1, y = 1000;  // Assume y range up to 1000 as per LeetCode constraints

        while (x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y);
            if (val == z) {
                result.push_back({x, y});
                x++; y--;  // move diagonally to avoid duplicates
            } else if (val < z) {
                x++;  // Need a bigger value → increase x
            } else {
                y--;  // Need a smaller value → decrease y
            }
        }

        return result;
    }
};
