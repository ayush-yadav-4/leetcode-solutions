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
    //    vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
    //    return helper(0,-1, nums, dp);

       vector<int>temp;
       temp.push_back(nums[0]);

       for(int i=1;i<nums.size();i++){
         if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
         }
         else{
            int idx = (lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin());
            temp[idx] = nums[i];
         }
       }
       return temp.size();
        
    }
};
