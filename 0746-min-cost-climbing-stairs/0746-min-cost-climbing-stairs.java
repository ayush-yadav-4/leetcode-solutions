class Solution {

    int help(int idx,  int[] cost,int[] dp){
        if(idx <0) return 0;
        if(idx == 0) return cost[0];
        if(idx == 1) return cost[1];
        
        if(dp[idx] != -1) return dp[idx];
        return dp[idx]= cost[idx] + Math.min(help(idx-1,cost,dp), help(idx-2,cost,dp));
    }
    public int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length];
        Arrays.fill(dp,-1);
        return Math.min(help(cost.length-1,cost,dp), help(cost.length-2,cost,dp));
    }
}