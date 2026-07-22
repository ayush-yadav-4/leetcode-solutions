class Solution {

    public String rearrangeString(String s, char x, char y) {

        int freq[] = new int[26];
       for(int i=0;i<s.length();i++){
         freq[s.charAt(i) - 'a']++;
       }
       StringBuilder ans = new StringBuilder();

       for(int i=0;i<freq[y-'a'];i++){
        ans.append(y);
       }

       for(int i=0;i<s.length();i++){
         if(s.charAt(i) == x || s.charAt(i) == y) continue;
         ans.append(s.charAt(i));
       }

       for(int i=0;i<freq[x-'a'];i++){
          ans.append(x);
       }

       return ans.toString();
    }
}