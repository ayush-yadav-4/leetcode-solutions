class Solution {
    public int[] decimalRepresentation(int n) {
        
      List<Integer> ls = new ArrayList<>();
      int i = 1;
        while(n != 0){
         int ans = ((n%10) * i);
         if(ans != 0){
            ls.add(ans);
         }
         i = i * 10;
         n = n /10;

        }
        
         int[] ans = new int[ls.size()];
       for( i = 0;i<ls.size();i++){
         ans[i] = ls.get(ls.size() - i - 1);
       }
       return ans;

    }
}