class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0,i=0;
        stack<char>st;
        while(s[i] != '\0'){
            if(s[i] == '('){
                open++;
            }
            else if(open >0){
               open--;
            }
            else{
               close++;
            }
            i++;
            
        }
        
        return open + close;
    }
};