class Solution {
public:
int helper(int idx,int sum1,int total,int target,vector<int>& arr,vector<vector<int>>&dp){
    if(idx == arr.size()) return (sum1 == target);
    //if(sum1 == target) return 1;
    
   if(dp[idx][sum1 + total] != -1) return dp[idx][sum1 + total];
   int plus = helper(idx+1,sum1+arr[idx],total,target,arr,dp);
     
   
   int neg  =  helper(idx+1,sum1-arr[idx],total,target,arr,dp);
   
   
    
    
    
    

    return dp[idx][sum1 + total] = plus+neg;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int total =0;
        for(int a : nums) total += a;
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*total+1,-1));
        return helper(0,0,total,target,nums,dp);
    }
};