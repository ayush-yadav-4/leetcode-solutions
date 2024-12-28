class Solution {
public:

    void Gen(vector<string> &ans,string &temp,int n ,int L, int R){
        if(L + R == 2*n){
           ans.push_back(temp);
        return;
        }

        if(L < n){
            temp.push_back('(');
             Gen(ans,temp,n,L+1,R);
            temp.pop_back();
        }

           if(R < L){
            temp.push_back(')');
             Gen(ans,temp,n,L,R+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
         vector<string>ans;   string temp;
         Gen(ans,temp,n,0,0);
         return ans;
    }
};