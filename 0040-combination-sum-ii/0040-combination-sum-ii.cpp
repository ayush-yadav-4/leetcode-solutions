class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& candidates, int target, int idx, vector<int>& temp) {
        if (target == 0) { 
            ans.push_back(temp); 
            return; 
        }
        if (target < 0 || idx == candidates.size()) return;

        // Include the current candidate
        temp.push_back(candidates[idx]);
        helper(ans, candidates, target - candidates[idx], idx + 1, temp);
        temp.pop_back();

        // Skip all duplicates for the current candidate
        while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
            idx++;
        }

        // Skip the current candidate
        helper(ans, candidates, target, idx + 1, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        helper(ans, candidates, target, 0, temp);
        return ans;
    }
};
