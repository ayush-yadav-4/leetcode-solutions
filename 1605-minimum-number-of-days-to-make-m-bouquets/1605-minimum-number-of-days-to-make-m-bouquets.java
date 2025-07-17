class Solution {
 boolean check(int[] bloomDay,int m,int k,int mid){
   int boq =0,flower=0;
    for(int it : bloomDay){
      if(it <= mid ){
        flower++;
        if(flower == k){
            boq++;
            flower = 0;
        }
    
      }
      else{
        flower = 0;
      }
    
    }
   return boq >=m;
}
    public int minDays(int[] bloomDay, int m, int k) {
        if(bloomDay.length < m*k) return -1;
        int st = Integer.MAX_VALUE,end = Integer.MIN_VALUE,mid=0,ans=-1;
         for(int it : bloomDay){
             st = Math.min(st,it);
             end = Math.max(end,it);
         }

         while(st<=end){
            mid = st + (end-st)/2;

            if(check(bloomDay,m,k,mid)){
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