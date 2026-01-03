class Solution {
public:
    bool helper(int i, int j, string s, string p, vector<vector<int>>& dp) {

        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;

        if (i < 0 && j >= 0) {
            for (int ii = j; ii >= 0; ii--) {
                if (p[ii] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool match = false, notmatch = false;

        if (s[i] == p[j] || p[j] == '?') {
            match = helper(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*') {
            notmatch = helper(i - 1, j, s, p, dp) ||
                       helper(i, j - 1, s, p, dp);
        }

        return dp[i][j] = match || notmatch;
    }

    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
       // return helper(s.size() - 1, p.size() - 1, s, p, dp);
       
        dp[0][0] = true;
        for(int j=1;j<=p.size();j++){
            bool flag = true;
             for(int i = j;i>=1;i--){
                if(p[i-1] != '*'){dp[0][j] = false; flag =false;}
             }

             dp[0][j] = flag;
        }



        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
              bool match = false,notmatch = false;

              if(s[i-1] == p[j-1] || p[j-1] == '?'){
              match = dp[i-1][j-1];
              }
              if(p[j-1] == '*'){
                notmatch = dp[i-1][j] || dp[i][j-1];
              }
              if(i == 1 && j >=1){

              }

              dp[i][j] = match || notmatch;
            }
        }

        return dp[s.size()][p.size()];
    }
};
