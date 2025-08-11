class Solution {
    public int lengthOfLongestSubstring(String s) {
       int freq[] = new int[256];
       Arrays.fill(freq,0);
        int ans = 0,f=0,end = 0;
        while(end<s.length()){
           while(freq[s.charAt(end)] != 0){          
                freq[s.charAt(f)]--;
                f++;      
           }
          
           freq[s.charAt(end)]++;
            ans = Math.max(ans,(end-f+1));
           end++;
        }
        return ans;
    }
}