class Solution {
public:
    int maxDepth(string s) {
        int ans=0,i=0,count=0;
       
        while(s[i] != '\0'){
          if(s[i] == '(')count++;
          else if(s[i] == ')' &&count>0){
            ans = max(ans,count); count--;
          }
          i++;
        }
        return ans;
    }
};