class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 0, y = 0;
        int n = positions.size();

        for (auto& p : positions) {
            x += p[0];
            y += p[1];
        }

        x /= n;
        y /= n;

        double step = 1.0;
        double eps = 1e-7;
        double prev = calcDist(x, y, positions);

        while (step > eps) {
            bool found = false;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    double nx = x + dx * step;
                    double ny = y + dy * step;
                    double dist = calcDist(nx, ny, positions);
                    if (dist < prev) {
                        prev = dist;
                        x = nx;
                        y = ny;
                        found = true;
                    }
                }
            }
            if (!found) {
                step *= 0.5;
            }
        }

        return prev;
    }

private:
    double calcDist(double x, double y, vector<vector<int>>& positions) {
        double total = 0;
        for (auto& p : positions) {
            double dx = x - p[0];
            double dy = y - p[1];
            total += sqrt(dx * dx + dy * dy);
        }
        return total;
    }
};
