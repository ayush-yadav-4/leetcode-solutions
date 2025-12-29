class Solution {
public:
int helper(int idx1,int idx2,string str1,string str2, vector<vector<int>>&dp){

    if(idx1<0 || idx2<0) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int match =0;
    if(str1[idx1] == str2[idx2]){
        match = 1 + helper(idx1-1,idx2-1,str1,str2,dp);
    }

    int notmatch = max(helper(idx1-1,idx2,str1,str2,dp), helper(idx1,idx2-1,str1,str2,dp));

    return dp[idx1][idx2] = max(match , notmatch);
}
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        //return helper(text1.size()-1,text2.size()-1,text1,text2,dp);

        // for(int i=0;i<text1.size();i++){
        //     dp[0][i] = 0;
        // }
        // for(int i=0;i<text2.size();i++){
        //     dp[i][0] = 0;
        // }

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){

                int match = 0;
                if(text1[i-1] == text2[j-1]){
                    match = 1 + dp[i-1][j-1];
                }
                int notmatch = max(dp[i-1][j],dp[i][j-1]);

                dp[i][j] = max(match, notmatch);
            }
        }

        return dp[text1.size()][text2.size()];
    }
};