class Solution {
public:
vector<int>dp;
  int helper(int n){
    if(n == 0)
       return 1;
    
    if(n==1) return 1;

    if(dp[n] != -1) return dp[n];
    int left = helper(n-1);
    int right = helper(n-2);
    return left + right;
  }
    int climbStairs(int n) {
        // dp.resize(n+1,-1);
        // int ans = 0;
        // ans = helper(n);

        //  vector<int>dp(n+1,-1);
        // dp[0] = 0;
        // return ans;

        if(n<=2) return n;
        int prev2 = 1,prev=2,curr  = 0;
        for(int i=3;i<=n;i++){
          curr = prev2+prev;
          prev2 = prev;
          prev = curr;
        }
        return curr;

       
    }
};