class Solution {
public:

    int myAtoi(string s) {
        int sign=1,i=0,c=0; long num =0;
        while(i<s.size() && s[i] == ' ')i++;
       
       if(i<s.size() && (s[i] == '-' || s[i] == '+')){
         sign = (s[i] == '-')?-1:1;
         i++;
       }

       while(i<s.size() && isdigit(s[i])){
        num = num*10 + (s[i] - '0');

        if(num*sign >= INT_MAX)return INT_MAX;
         if(num*sign <= INT_MIN)return INT_MIN;
         i++;
       }
        
     
        return num*sign;
    }
};