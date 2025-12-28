class Solution {
public:
int helper(int idx,int amt, vector<int>& arr,vector<vector<int>>&dp){

    //if(amt ==0) return 1;
    if(amt ==0) return 1;
    if(idx == arr.size()-1){ 
        if(amt%arr[idx] ==0) return 1;
        return 0;
        }
 if(dp[idx][amt] != -1) return dp[idx][amt];
    int pick = 0;
    if(arr[idx]<= amt){
        pick = helper(idx,amt-arr[idx],arr,dp);
    }

    int nopick = helper(idx+1,amt,arr,dp);

    return dp[idx][amt] = pick+nopick;

}
    int change(int amount, vector<int>& coins) {
         vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));

         return helper(0,amount,coins,dp);
    }
};