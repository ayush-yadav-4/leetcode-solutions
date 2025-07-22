class Solution {
public:
    bool checkValidString(string s) {
        
        
        int min=0,max=0,i=0;
        while(s[i] != '\0'){
           if(s[i] == '('){
            max = max + 1;
            min = min + 1;
           }
           else if(s[i] == ')'){
             max = max - 1;
             min = min -1;
           }
           else{
            min = min -1;
            max = max + 1;
           }
           if(min<0)min = 0;
           i++;
           if(max < 0) return false;
        }
        

        return (min == 0);   
         }
};