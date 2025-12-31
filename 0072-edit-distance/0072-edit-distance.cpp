class Solution {
public:
   int helper(int i,int j,string s1, string s2,vector<vector<int>>&dp){
    
    if(j<0 && i >=0) return i+1;
    if(i<0 && j>=0) return j+1;
    if(i<0 && j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int match = INT_MAX,notmatch = INT_MAX;
    if(s1[i] == s2[j]){
        match = helper(i-1,j-1,s1,s2,dp);
    }
    else{
        notmatch = 1 + min(helper(i-1,j-1,s1,s2,dp),min(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp)));
    }
    return dp[i][j] = min(match , notmatch);
}
    int minDistance(string s1, string s2) {
         vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
         return helper(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
};