class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        // Convert time points to minutes
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the time points
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        int n = minutes.size();

        // Find the minimum difference between adjacent time points
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Check the circular difference between the first and last time point
        int circularDiff = (minutes[0] + 1440) - minutes[n - 1];
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};