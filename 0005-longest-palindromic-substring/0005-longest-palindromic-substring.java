class Solution {
    public String longestPalindrome(String s) {
        if(s.length() <=1) return s;
        int low = 0, high = 0; String ans = "";
        String str ="";
        for(int i=1;i<s.length();i++){
           
           low = i ; high = i;

           while(s.charAt(low) == s.charAt(high)){
              low--;
              high++;

              if(low == -1 || high == s.length()){
                break;
              }
           }

            str = s.substring(low+1,high);
           if(ans.length() < str.length()){
             ans = str;
           }

           low = i-1 ; high = i;

           while(s.charAt(low) == s.charAt(high)){
              low--;
              high++;

              if(low == -1 || high == s.length()){
                break;
              }
           }

           str = s.substring(low+1,high);
           if(ans.length() < str.length()){
             ans = str;
           }


        }

        return ans;
    }
}