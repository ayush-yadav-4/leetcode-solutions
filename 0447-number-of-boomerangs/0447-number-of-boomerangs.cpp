class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> distanceCount;

            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distSq = dx * dx + dy * dy;

                distanceCount[distSq]++;
            }

            for (auto& [dist, count] : distanceCount) {
                res += count * (count - 1);  // m * (m - 1) boomerangs
            }
        }

        return res;
    }
};
