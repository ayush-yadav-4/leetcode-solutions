class Solution {
  
    public int beautySum(String s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
              HashMap<Character,Integer> mp = new HashMap<>();
            for(int j=i;j<s.length();j++){
               mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0) +1);
            
           int mini = Integer.MAX_VALUE, maxi = Integer.MIN_VALUE;
       for (int val : mp.values()) {
    mini = Math.min(mini, val);
    maxi = Math.max(maxi, val);
}
            ans += (maxi - mini);
            }
        }
        return ans;
    }
}