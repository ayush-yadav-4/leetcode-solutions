class Solution {
    public int largestAltitude(int[] gain) {
       int prefix = 0,ans =0;
       for(int i=0;i<gain.length;i++){
          prefix += gain[i];
          ans = Math.max(ans,prefix);
       } 
       return ans;
    }
}