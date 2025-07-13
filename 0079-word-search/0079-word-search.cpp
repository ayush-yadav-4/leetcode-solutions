class Solution {
public:
    bool helper(vector<vector<char>>& board, vector<vector<int>>& vis, string& word, int row, int col, int idx) {
        if (idx == word.size()) return true; // full word matched

        // Check bounds and matching character
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()
            || vis[row][col] == 1 || board[row][col] != word[idx]) {
            return false;
        }

        vis[row][col] = 1;  // mark visited

        int rows[] = {0, 0, -1, 1};
        int cols[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int r = row + rows[i];
            int c = col + cols[i];

            if (helper(board, vis, word, r, c, idx + 1)) return true;
        }

        vis[row][col] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, vis, word, i, j, 0)) return true;
                }
            }
        }

        return false;
    }
};
