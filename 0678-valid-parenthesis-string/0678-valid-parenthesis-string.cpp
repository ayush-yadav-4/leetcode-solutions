class Solution {
public:
    bool checkValidString(string s) {
    
    int i=0,left=0,right=0;
      while(s[i] != '\0'){
        char a = s[i];
        if(a == '('){left++;right++;}
        else if(a == ')'){
            left--; right--;
        }else{
           left--;
           right++;
        }
        if(left<0) left = 0;
        if(right<0) return false;
        i++;
      } 
     
      
        return left == 0;
        
    }
};