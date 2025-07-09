class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());
        int x = pos[0], y = pos[1], z = pos[2];

        int left_gap = y - x - 1;
        int right_gap = z - y - 1;

        int max_moves = left_gap + right_gap;

        int min_moves = 0;
        if (left_gap == 0 && right_gap == 0) {
            min_moves = 0;
        } else if (left_gap <= 1 || right_gap <= 1) {
            min_moves = 1;
        } else {
            min_moves = 2;
        }

        return {min_moves, max_moves};
    }
};
