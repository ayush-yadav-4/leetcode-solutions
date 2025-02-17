class Solution {
public:
    int maxDepth(string s) {
        int ans=0,i=0;
        stack<char>st;
        while(s[i] != '\0'){
          if(s[i] == '(')st.push('(');
          else if(s[i] == ')' && !st.empty()){
            ans = max(ans,(int)st.size()); st.pop();
          }
          i++;
        }
        return ans;
    }
};