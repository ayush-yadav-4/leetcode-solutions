class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        // if (intervals.size() <= 1) return intervals;

    
        // sort(intervals.begin(), intervals.end());

        // vector<vector<int>> ans;
        // vector<int> temp = intervals[0]; 

        // for (const auto& interval : intervals) {
        //     if (interval[0] <= temp[1]) {
               
        //         temp[1] = max(temp[1], interval[1]);
        //     } else {
               
        //         ans.push_back(temp);
        //         temp = interval;
        //     }
        // }

        // ans.push_back(temp);
        // return ans;

         vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        ans.push_back({arr[0][0],arr[0][1]});
        for(int i=1;i<arr.size();i++){
             if(!ans.empty() && ans.back()[1] >= arr[i][0]){
                ans.back()[1] = max(arr[i][1],ans.back()[1]);
             }
            else{
                ans.push_back({arr[i][0],arr[i][1]});
            }
        }
        return ans;

        //TC = O(N*LognN) sorting array + O(N)  Traversal
    }
};
