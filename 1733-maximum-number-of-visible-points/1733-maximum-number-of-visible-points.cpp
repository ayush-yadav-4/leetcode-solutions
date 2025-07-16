class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> polarAngles;
        int sameLocation = 0;

        for (auto& point : points) {
            int dx = point[0] - location[0];
            int dy = point[1] - location[1];

            if (dx == 0 && dy == 0) {
                sameLocation++;
                continue;
            }

            double theta = atan2(dy, dx) * 180.0 / M_PI;
            if (theta < 0) theta += 360.0;
            polarAngles.push_back(theta);
        }

        sort(polarAngles.begin(), polarAngles.end());

        // Duplicate and extend each angle by 360 to handle circular window
        int n = polarAngles.size();
        for (int i = 0; i < n; ++i) {
            polarAngles.push_back(polarAngles[i] + 360.0);
        }

        int maxVisible = 0;
        int l = 0;

        for (int r = 0; r < polarAngles.size(); ++r) {
            while (polarAngles[r] - polarAngles[l] > angle) {
                l++;
            }
            maxVisible = max(maxVisible, r - l + 1);
        }

        return maxVisible + sameLocation;
    }
};
