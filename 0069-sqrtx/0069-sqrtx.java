class Solution {
    public int mySqrt(int x) {
        //return (int)Math.sqrt(x);

        int st = 1, end = x,ans = 0;

        while(st<=end){
          int mid  = st + (end-st)/2;
          long num = (long)mid * mid;
          
           if(num <=x){
            ans = mid;
            st = mid+1;
          }
          else{
            end = mid - 1;
          }
        }
        return ans;
    }
}