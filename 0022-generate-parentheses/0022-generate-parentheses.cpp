class Solution {
public:
void helper(int open , int close , string str , int n, vector<string>& ans){
   if(open > n || close > open) return;
   if(open == n && close == n){
      ans.push_back(str);
      return;
   }

   if(open < n){
     str.push_back('(');
     helper(open+1,close, str,n, ans);
     str.pop_back();
   }

   if(close < open){
    str.push_back(')');
     helper(open , close+1,str,n,ans);
     str.pop_back();
   }


}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        helper(0,0,str,n,ans);
        return ans;
    }
};