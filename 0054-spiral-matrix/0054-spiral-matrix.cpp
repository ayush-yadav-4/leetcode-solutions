class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l =0 , r = matrix[0].size()-1,u = 0 , d = matrix.size()-1;
       vector<int>ans;
     while (l <= r && u <= d) {
        // Traverse top row
        for (int i = l; i <= r; i++) {
            ans.push_back(matrix[u][i]);
        }
        u++; // Move down the upper boundary

        // Traverse right column
        for (int i = u; i <= d; i++) {
            ans.push_back(matrix[i][r]);
        }
        r--; // Move left the right boundary

        // Traverse bottom row (only if u <= d to avoid duplicates)
        if (u <= d) {
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[d][i]);
            }
            d--; // Move up the lower boundary
        }

        // Traverse left column (only if l <= r to avoid duplicates)
        if (l <= r) {
            for (int i = d; i >= u; i--) {
                ans.push_back(matrix[i][l]);
            }
            l++; // Move right the left boundary
        }
    }
        return ans;
    }
};