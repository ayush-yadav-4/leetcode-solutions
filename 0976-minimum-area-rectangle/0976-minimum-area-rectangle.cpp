class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<string> pointSet;
        
        // Insert all points into a set for quick lookup
        for (auto& p : points) {
            pointSet.insert(to_string(p[0]) + "," + to_string(p[1]));
        }
        
        int minArea = INT_MAX;
        int n = points.size();
        
        // Try every pair of points
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                // Must be diagonal (x and y must differ)
                if (x1 != x2 && y1 != y2) {
                    // Check if other two points exist
                    string p1 = to_string(x1) + "," + to_string(y2);
                    string p2 = to_string(x2) + "," + to_string(y1);
                    if (pointSet.count(p1) && pointSet.count(p2)) {
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        
        return minArea == INT_MAX ? 0 : minArea;
    }
};
