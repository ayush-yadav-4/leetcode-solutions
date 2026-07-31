class Solution {
   
    public int totalFruit(int[] fruits) {
    int ans =0, cnt=0, r=0,l=0;
    Map<Integer, Integer>mp = new HashMap<>();
      while(r<fruits.length){
        mp.put(fruits[r], mp.getOrDefault(fruits[r],0)+1);
        cnt++;
        while(l<r && mp.size() > 2){
          mp.put(fruits[l],mp.get(fruits[l])-1);
          if(mp.get(fruits[l]) == 0){
            mp.remove(fruits[l]);
          }
          cnt--;
          l++;
          
        }
       ans = Math.max(ans, cnt);
       r++;
      }

      return ans;
    }
}