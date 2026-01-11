class Solution {
    public int residuePrefixes(String s) {
        Map<Character,Integer> mp = new HashMap<>();
        int ans =0,n=0;
        if(s.length()%3 == 0){
            n = s.length()-1;
        }
        else n = s.length();
        for(int i=0;i<n;i++){
            
          mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i),0) + 1);
          if(mp.size() == (i+1)%3)
           ans++;
        }
        return ans;
    }
}