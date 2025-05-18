class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int rowMask = 0, colMask = 0;

        // Create masks from the first row and first column
        for (int i = 0; i < n; ++i) {
            rowMask |= board[0][i] << i;
            colMask |= board[i][0] << i;
        }

        int reverseRowMask = ((1 << n) - 1) ^ rowMask;
        int reverseColMask = ((1 << n) - 1) ^ colMask;

        int rowCount = 0, colCount = 0;

        for (int i = 0; i < n; ++i) {
            int currRowMask = 0, currColMask = 0;
            for (int j = 0; j < n; ++j) {
                currRowMask |= board[i][j] << j;
                currColMask |= board[j][i] << j;
            }

            // Invalid if not equal to rowMask or its inverse
            if (currRowMask != rowMask && currRowMask != reverseRowMask)
                return -1;
            if (currColMask != colMask && currColMask != reverseColMask)
                return -1;

            if (currRowMask == rowMask) rowCount++;
            if (currColMask == colMask) colCount++;
        }

        // Check moves needed
        int rowMoves = getMoves(rowMask, rowCount, n);
        int colMoves = getMoves(colMask, colCount, n);
        if (rowMoves == -1 || colMoves == -1) return -1;
        return rowMoves + colMoves;
    }

    int getMoves(int mask, int count, int n) {
        int ones = __builtin_popcount(mask);

        // Invalid configuration
        if (abs(n - 2 * ones) > 1 || abs(n - 2 * count) > 1) return -1;

        int evenPattern = 0xAAAAAAAA & ((1 << n) - 1); // 1010...
        int oddPattern  = 0x55555555 & ((1 << n) - 1); // 0101...

        int movesEven = __builtin_popcount(mask ^ evenPattern);
        int movesOdd  = __builtin_popcount(mask ^ oddPattern);

        if (n % 2 == 0) {
            return min(movesEven, movesOdd) / 2;
        } else {
            // Choose the one with correct number of 1s
            if (ones * 2 > n) {
                return movesOdd / 2;
            } else {
                return movesEven / 2;
            }
        }
    }
};
