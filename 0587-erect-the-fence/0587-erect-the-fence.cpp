class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());

        int n = trees.size();
        if (n <= 3) return trees;

        // Helper lambda to calculate cross product
        auto cross = [](vector<int>& o, vector<int>& a, vector<int>& b) {
            return (a[0] - o[0]) * (b[1] - o[1]) - 
                   (a[1] - o[1]) * (b[0] - o[0]);
        };

        vector<vector<int>> hull;

        // Build lower hull
        for (int i = 0; i < n; ++i) {
            while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), trees[i]) < 0)
                hull.pop_back();
            hull.push_back(trees[i]);
        }

        // Build upper hull
        int lowerSize = hull.size();
        for (int i = n - 2; i >= 0; --i) {
            while (hull.size() > lowerSize && cross(hull[hull.size()-2], hull.back(), trees[i]) < 0)
                hull.pop_back();
            hull.push_back(trees[i]);
        }

        // Remove duplicate last point
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};
