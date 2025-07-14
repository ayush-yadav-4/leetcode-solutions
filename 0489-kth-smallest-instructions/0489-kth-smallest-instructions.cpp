class Solution {
public:
    int comb[31][31] = {0};

    void buildCombTable() {
        for (int i = 0; i <= 30; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j)
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        buildCombTable();

        int v = destination[0];
        int h = destination[1];
        string res = "";

        while (v + h > 0) {
            if (h > 0) {
                int count = comb[v + h - 1][h - 1];  // if we place 'H' now, how many ways to complete
                if (k <= count) {
                    res += 'H';
                    --h;
                } else {
                    res += 'V';
                    --v;
                    k -= count;
                }
            } else {
                res += 'V';
                --v;
            }
        }
        return res;
    }
};
