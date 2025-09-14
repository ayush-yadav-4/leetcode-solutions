class Solution {
public:
    void helper(vector<string>&ans,int n, int occ,int cc,string s){
       if(occ == n && cc == n){ ans.push_back(s); return;}

       if(occ<n){
        helper(ans,n,occ+1,cc,s+"(");
       }
       if(cc < occ){
         helper(ans,n,occ,cc+1,s+")");
       }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        helper(ans,n,0,0,"");
        return ans;
    }
};