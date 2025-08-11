class Solution {
    public int numberOfSubstrings(String s) {
        int[] idx = new int[3];
        Arrays.fill(idx,-1);
        int ans = 0;
      for(int i=0;i<s.length();i++){
        idx[s.charAt(i)-'a'] = i;
         ans = ans + (1+ Math.min(idx[0],Math.min(idx[1],idx[2])));
      }
        return ans;
    }
}