class Solution {
    Boolean check(Map<Character,Integer>mp){

        int ans = -1;
        for(Map.Entry<Character,Integer> m : mp.entrySet()){
          if(ans == -1){
            ans = m.getValue();
          }
          if(ans != m.getValue()) return false;
        }
        return true;
    }
    public int longestBalanced(String s) {
        // Map<Character,Integer>mp = new HashMap<>();
        //    int ans = 0;
        // for(int i=0;i<s.length();i++){
        //     mp.clear();
        //     for(int j = i;j<s.length();j++){
        //         mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j),0) + 1);
        //         if(check(mp)) ans  = Math.max(ans,(j-i+1));
        //     }
        // }
        // return ans;

         int n = s.length();
    int ans = 1;

    for (int i = 0; i < n; i++) {
        int[] freq = new int[26];
        int distinct = 0, maxFreq = 0;

        for (int j = i; j < n; j++) {
            int idx = s.charAt(j) - 'a';

            if (freq[idx] == 0) distinct++;
            freq[idx]++;
            maxFreq = Math.max(maxFreq, freq[idx]);

            int len = j - i + 1;
            if (maxFreq * distinct == len) {
                ans = Math.max(ans, len);
            }
        }
    }
    return ans;
    }
}