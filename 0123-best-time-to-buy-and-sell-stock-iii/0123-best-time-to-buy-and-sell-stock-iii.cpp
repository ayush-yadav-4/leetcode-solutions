class Solution {
public:

    int helper(int idx ,int cnt,int buy,vector<int>& prices,vector<vector<vector<int>>>&dp ){

        if(idx == prices.size()){
            return 0;
        }
            if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];
        int profit =0;
        if(buy == 1 && cnt>0){
             profit =  max(-prices[idx] + helper(idx+1,cnt,0,prices,dp),helper(idx+1,cnt,1,prices,dp));
        }
        else if(cnt>0){
          profit = max(prices[idx] + helper(idx+1,cnt-1,1,prices,dp),helper(idx+1,cnt,0,prices,dp));
        }
        return dp[idx][buy][cnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
      
        return helper(0,2,1,prices,dp);
    }
};