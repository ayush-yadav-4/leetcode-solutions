class Solution {
   boolean check(int[] piles, int h, int mid){
     int cnt = 0;
     for(int i=0;i<piles.length;i++){
       if(piles[i]%mid == 0){
         cnt += piles[i]/mid;
       }
       else{
         cnt += (piles[i]/mid)+1;
       }
       if(cnt > h) return false;
     }

     if(cnt<=h) return true;
     return false;
   }
    public int minEatingSpeed(int[] piles, int h) {
        int st=1, end =0;
        int ans = 0;
        for(int i=0;i<piles.length;i++){
          end = Math.max(end, piles[i]);
        }
        
        while(st<=end){
            int mid = st + (end-st)/2;
            if(check( piles,h,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid + 1;
            }
        }

        return ans;
            
    }
}