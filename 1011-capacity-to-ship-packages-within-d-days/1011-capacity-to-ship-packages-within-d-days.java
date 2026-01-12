class Solution {
    boolean check(int capacity,int[] weights, int days){

        int ans = 0,req=1;
        for(int num : weights){
            if(num > capacity) return false;
           if((ans + num ) <= capacity){
            ans += num;

           }else{
            req++;
            ans = num;
           }
        }

        if(req<=days) return true;

        return false;
    }
    public int shipWithinDays(int[] weights, int days) {
                int st = 1, end = 0;
        for(int a : weights){
          end  += a;
        }
        int ans =end;
        while(st<=end){
          int mid = st + (end-st)/2;

          if(check(mid,weights,days)){
            ans = mid;
            end = mid-1;
          }
          else{
            st= mid+1;
          }
        }
        return ans;
    }
}