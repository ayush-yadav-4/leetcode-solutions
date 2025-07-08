class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        int n = d.size();
        for (int i = 3; i < n; i++) {
            // Case 1: current line crosses line 3 steps before
            if (d[i] >= d[i-2] && d[i-1] <= d[i-3]) {
                return true;
            }

            // Case 2: current line overlaps line 4 steps before
            if (i >= 4 && d[i-1] == d[i-3] && d[i] + d[i-4] >= d[i-2]) {
                return true;
            }

            // Case 3: current line crosses line 5 steps before
            if (i >= 5 && d[i-2] >= d[i-4] &&
                d[i-3] >= d[i-1] &&
                d[i-1] + d[i-5] >= d[i-3] &&
                d[i] + d[i-4] >= d[i-2]) {
                return true;
            }
        }
        return false;
    }
};
