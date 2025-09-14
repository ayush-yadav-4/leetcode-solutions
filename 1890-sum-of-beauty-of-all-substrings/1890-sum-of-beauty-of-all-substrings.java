class Solution {
  
    public int beautySum(String s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
              int[] freq = new int[26];
              Arrays.fill(freq,0);
            for(int j=i;j<s.length();j++){
               freq[s.charAt(j) - 'a']++;
                int mini = Integer.MAX_VALUE, maxi = Integer.MIN_VALUE;
               for(int k=0;k<26;k++){
                 if (freq[k] > 0) { // only consider characters present
                        maxi = Math.max(maxi, freq[k]);
                        mini = Math.min(mini, freq[k]);
                    }
               }
              
            
          
  
            ans += (maxi - mini);
            }
        }
        return ans;
    }
}