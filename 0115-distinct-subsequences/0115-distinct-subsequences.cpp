class Solution {
public:

int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp){

    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
 
    int match =0,notmatch = 0;
    if(s1[i] == s2[j]){
        match = helper(i-1,j-1,s1,s2,dp) + helper(i-1,j,s1,s2,dp);
    }
    else{
         notmatch = helper(i-1,j,s1,s2,dp);
    }
       
    
    return dp[i][j] = match + notmatch;
}
    int numDistinct(string s1, string s2) {
        
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));

        return helper(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
};