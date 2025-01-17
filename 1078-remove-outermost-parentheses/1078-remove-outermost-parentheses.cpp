class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter =0; int i=0; string ans;
        while(s[i] !='\0'){
            if( s[i] == '(' ){
                if(counter>0) ans+=s[i];
                counter++;
             
            }
            else if(s[i] == ')'){
                counter--;
               if(counter>0){ ans +=s[i];}
               
            }

            i++;
        }
        return ans;
    }
};