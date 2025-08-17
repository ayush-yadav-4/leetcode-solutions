class Solution {
    public int beautySum(String s) {
        int total = 0;
        for(int i=0;i<s.length();i++){
           int[] freq = new int[26];
             int maxf =  0;
           for(int j=i;j<s.length();j++){
               
               int idx = s.charAt(j) - 'a';
               freq[idx]++;
               maxf = Math.max(maxf,freq[idx]);
              
               
               int minf = Integer.MAX_VALUE;
               for(int k=0;k<26;k++){
                  if(freq[k] > 0){
                     minf = Math.min(minf,freq[k]);
                  }
               }
               total += (maxf - minf);

           }
        }
        return total;
    }
}