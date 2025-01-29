class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

    
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> temp = intervals[0]; 

        for (const auto& interval : intervals) {
            if (interval[0] <= temp[1]) {
               
                temp[1] = max(temp[1], interval[1]);
            } else {
               
                ans.push_back(temp);
                temp = interval;
            }
        }

        ans.push_back(temp);
        return ans;
    }
};
