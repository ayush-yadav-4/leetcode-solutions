class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int result = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopeCount;
            int same = 1; // count the point itself
            int vertical = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++; // same point
                } else if (dx == 0) {
                    vertical++;
                } else {
                    int g = gcd(dy, dx);
                    dy /= g;
                    dx /= g;

                    // normalize direction (to avoid (1,-1) vs (-1,1))
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    slopeCount[{dy, dx}]++;
                    currMax = max(currMax, slopeCount[{dy, dx}]);
                }

                currMax = max(currMax, vertical);
            }

            result = max(result, currMax + same);
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
