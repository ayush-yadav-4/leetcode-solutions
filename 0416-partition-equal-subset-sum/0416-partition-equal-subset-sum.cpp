class Solution {
public:

bool helper(int idx , int sum1 , int total,vector<int>& arr,vector<vector<int>>& dp){
   if(sum1 == (total - sum1)) return true;

   if(idx == arr.size()-1){
     if((sum1+arr[idx]) == total -(sum1+arr[idx]) ) return true;
     return false;
   }
     if(dp[idx][sum1] != -1) return dp[idx][sum1];
   bool pick = false;
   if(sum1+arr[idx] <= total){
    pick = helper(idx+1,sum1+arr[idx], total,arr,dp);
   }

   bool nopick = helper(idx+1,sum1,total,arr,dp);

   return dp[idx][sum1] = pick || nopick;
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
             sum += nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));

        return helper(0,0,sum,nums,dp);
    }
};