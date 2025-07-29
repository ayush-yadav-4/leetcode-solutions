#include <vector>
#include <unordered_map>
#include <cmath>
#include <tuple>
using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double minArea = DBL_MAX;
        unordered_map<string, vector<pair<int, int>>> mp;

        // Store all pairs with the same midpoint and distance squared
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                // Midpoint
                double mx = (x1 + x2) / 2.0;
                double my = (y1 + y2) / 2.0;
                // Length squared of diagonal
                double d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
                string key = to_string(mx) + "#" + to_string(my) + "#" + to_string(d);
                mp[key].emplace_back(i, j);
            }
        }

        for (auto& [key, vec] : mp) {
            if (vec.size() < 2) continue;
            // Try all combinations of diagonal pairs
            for (int i = 0; i < vec.size(); ++i) {
                for (int j = i + 1; j < vec.size(); ++j) {
                    auto [a1, a2] = vec[i];
                    auto [b1, b2] = vec[j];
                    // Form rectangle with three points: p1, p2, p3
                    auto& p1 = points[a1];
                    auto& p2 = points[a2];
                    auto& p3 = points[b1];
                    // Use vector math: area = |AB x AC|
                    double abx = p2[0] - p1[0];
                    double aby = p2[1] - p1[1];
                    double acx = p3[0] - p1[0];
                    double acy = p3[1] - p1[1];
                    double area = abs(abx * acy - aby * acx);
                    minArea = min(minArea, area);
                }
            }
        }

        return minArea == DBL_MAX ? 0.0 : minArea;
    }
};
