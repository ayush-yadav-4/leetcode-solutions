class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // Check if all points are distinct
        if (points[0] == points[1] || points[1] == points[2] || points[0] == points[2])
            return false;

        // Use cross product to check if they are not colinear
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];

        return (x2 - x1)*(y3 - y1) != (y2 - y1)*(x3 - x1);
    }
};
