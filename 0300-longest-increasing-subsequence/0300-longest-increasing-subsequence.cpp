class Solution {
public:
    int ans = 0;

    int helper(int idx, int prev_idx,vector<int>& nums, vector<vector<int>>& dp) {
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        int pick =0;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            pick = 1 + helper(idx+1,idx,nums,dp);
        }
        int notpick = helper(idx+1,prev_idx,nums,dp);

        return dp[idx][prev_idx+1] = max(pick,notpick);
    }

    int lengthOfLIS(vector<int>& nums) {
       vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
       return helper(0,-1, nums, dp);
        
    }
};
