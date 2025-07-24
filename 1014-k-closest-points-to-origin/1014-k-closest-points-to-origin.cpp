class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: pair<distance, point>
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y; // squared distance
            
            maxHeap.push({dist, point});
            
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove the farthest point
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
