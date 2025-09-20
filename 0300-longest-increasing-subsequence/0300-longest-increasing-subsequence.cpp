class Solution {
public:
int helper(vector<int>& arr,int idx,int prev_idx,vector<vector<int>>&dp){
   if(idx == arr.size()){
    
     return 0;
   }
   if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];

   int notpick = helper(arr,idx+1,prev_idx,dp);
   int pick = 0;
   if(prev_idx == -1 || arr[prev_idx] < arr[idx]){
    pick = 1 +helper(arr,idx+1,idx,dp);
   }

   return dp[idx][prev_idx+1] = max(pick , notpick);
}
    int lengthOfLIS(vector<int>& nums) {
         vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));

         return helper(nums,0,-1,dp);
    }
};