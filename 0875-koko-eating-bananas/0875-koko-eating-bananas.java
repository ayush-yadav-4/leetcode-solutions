class Solution {
    boolean check(int mid , int[] piles, int h){
        int ans =0;
       for(int num : piles){
          if(num%mid == 0){
            ans += num/mid;
          }
          else{
            ans += (num/mid + 1);
          }
          if(ans>h) return false;
       }
       if(ans <= h) return true;
       return false;
    }
    public int minEatingSpeed(int[] piles, int h) {
        
        int st = 1, end = 0;
        for(int a : piles){
          end  = Math.max(end,a);
        }
        int ans =0;
        while(st<=end){
          int mid = st + (end-st)/2;

          if(check(mid,piles,h)){
            ans = mid;
            end = mid-1;
          }
          else{
            st = mid+1;
          }
        }
        return ans;
    }
}