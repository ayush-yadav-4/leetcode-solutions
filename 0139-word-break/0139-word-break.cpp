class Solution {
public:
int helper(int idx, string s, vector<int>& dp,set<string> wordDict){
  if(idx == s.size()) return true;
  if(dp[idx] != -1) return dp[idx];

  string temp;
  for(int i=idx;i<s.size();i++){
      temp += s[i];
      if(wordDict.find(temp) != wordDict.end()){
             if(helper(i+1,s,dp,wordDict)) return 1;
      }

      
  }
  return dp[idx] = 0;

}
    bool wordBreak(string s, vector<string>& arr) {
       vector<int>dp(s.size()+1,-1);
      set<string>wordDict;
      for(string s : arr){
        wordDict.insert(s);
      }
       return helper(0,s,dp,wordDict);
    }
};