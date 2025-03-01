class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n); 
        
        unordered_map<int, vector<int>> diagonals;
        
     
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }
        
       
        for (int d = 0; d < m + n - 1; ++d) {
            if (d % 2 == 0) {
            
                reverse(diagonals[d].begin(), diagonals[d].end());
            }
            result.insert(result.end(), diagonals[d].begin(), diagonals[d].end());
        }
        
        return result;
    }
};
