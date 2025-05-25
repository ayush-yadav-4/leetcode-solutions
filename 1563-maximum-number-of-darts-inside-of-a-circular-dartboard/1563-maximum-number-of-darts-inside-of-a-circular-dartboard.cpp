class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int maxCount = 1;
        double R = static_cast<double>(r);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<pair<double, double>> centers = getCircleCenters(darts[i], darts[j], R);
                for (auto& center : centers) {
                    int count = 0;
                    for (int k = 0; k < n; ++k) {
                        if (distance(center, darts[k]) <= R + 1e-8) {
                            count++;
                        }
                    }
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }

    // Get circle centers from two points and radius
    vector<pair<double, double>> getCircleCenters(vector<int>& A, vector<int>& B, double r) {
        double x1 = A[0], y1 = A[1];
        double x2 = B[0], y2 = B[1];
        double dx = x2 - x1;
        double dy = y2 - y1;
        double d2 = dx * dx + dy * dy;
        double dist = sqrt(d2) / 2.0;

        if (dist > r) return {};  // No such circle can pass through both

        double midx = (x1 + x2) / 2.0;
        double midy = (y1 + y2) / 2.0;
        double h = sqrt(r * r - dist * dist);

        // Perpendicular vector (normalized)
        double nx = -dy / sqrt(d2);
        double ny = dx / sqrt(d2);

        // Two possible centers
        return {
            {midx + h * nx, midy + h * ny},
            {midx - h * nx, midy - h * ny}
        };
    }

    double distance(pair<double, double> center, vector<int>& pt) {
        double dx = center.first - pt[0];
        double dy = center.second - pt[1];
        return sqrt(dx * dx + dy * dy);
    }
};
