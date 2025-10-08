class Solution {
    boolean helper(int[] arr,int mid,int h){
       int time = 0;
       for(int i=0;i<arr.length;i++){
            if(arr[i] % mid == 0){
                time += (arr[i]/mid);
            }
            else{
                 time += (arr[i]/mid) + 1;
            }
           if(time > h) return false;
       }

      if(time <= h) return true;
      return false;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int ans = 0;
        int st = 1,end = 0,mid=0,maxi =0;
        for(int i=0;i<piles.length;i++){
            maxi = Math.max(piles[i],maxi);
        }
        end = maxi;
        while(st <= end){
             mid = st + (end- st)/2;

             if(helper(piles,mid,h)){
                ans = mid;
                end = mid -1;
             }
             else{
                st = mid+1;
             }
        }

        return ans;
    }
}