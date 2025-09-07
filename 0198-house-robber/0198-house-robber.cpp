class Solution {
public:
int helper(vector<int>& nums,int idx , vector<int>& dp){
  if(idx ==1 ) return max(nums[0],nums[1]);
  if(idx == 0) return nums[0];
 if(dp[idx]!=-1)return dp[idx];
  int count = nums[idx] + helper(nums,idx-2,dp);
  int nocount = helper(nums,idx-1,dp);

  return dp[idx] = max(count,nocount);
}
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
       // if(nums.size() == 2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size()+1,-1);
        return helper(nums,nums.size()-1,dp);
        
    }
};