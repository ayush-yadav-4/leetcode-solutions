class Solution {
public:
int helper(int i, int j, vector<vector<int>>& dp,vector<vector<int>>& arr){

    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0 || arr[i][j] == 1) return 0;
      if(dp[i][j] != -1) return dp[i][j];
    int up = helper(i-1,j,dp,arr);
    int back = helper(i,j-1,dp,arr);

    return dp[i][j] = up + back;
}
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {

        if(arr[0][0] == 1) return 0;
        vector<vector<int>>dp(arr.size(),vector<int>(arr[0].size(),-1));
        return helper(arr.size()-1,arr[0].size()-1,dp,arr);
    }
};