class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st; int i=0; string ans;
        while(s[i] !='\0'){
            if(!st.empty() && s[i] == '(' ){
                ans +=s[i];
             
            }
             if(s[i] == ')'){
                st.pop();
                if(!st.empty())ans+=s[i];
                
            }
            else st.push(s[i]);
            i++;
        }
        return ans;
    }
};