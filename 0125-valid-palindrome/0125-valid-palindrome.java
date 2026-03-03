class Solution {
    public boolean isPalindrome(String s) {
        
        StringBuilder str = new StringBuilder();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
          if(c>='a' && c<='z' || c >='A' && c <= 'Z' || c>='0' && c<='9'){
           str.append(c);
          }

        }
       
        String str1 = str.toString().toLowerCase();
        str.reverse();
        if(str.toString().toLowerCase().equals(str1)) return true;
        return false;
    }
}