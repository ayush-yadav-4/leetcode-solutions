class Solution {
    public String reverseWords(String s) {
        s = s.trim();
         StringBuilder str= new StringBuilder(s);
         str.reverse();
        char[] ch = s.trim().toCharArray();
        StringBuilder ans = new StringBuilder();
        int r =0; int l=0;
        while(r<str.length()){
           while(r<str.length() && str.charAt(r) != ' ')r++;
           StringBuilder word = new StringBuilder(str.substring(l,r));
           word.reverse();
           ans.append(word.toString());
           
          
          
            while(r<str.length() && str.charAt(r) == ' ')r++;
            if(r < s.length())ans.append(" ");
            l = r;

        }
        return ans.toString();
    }
}