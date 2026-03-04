class Solution {
    public String trimTrailingVowels(String s) {
        int r = s.length()-1;
        while(r>=0){
            char ch = s.charAt(r);
          if(ch == 'a' || ch == 'e' || ch=='i' || ch == 'o' || ch == 'u'){
           r--;
          }
          else break;
        }

        return s.substring(0,r+1);
    }
}