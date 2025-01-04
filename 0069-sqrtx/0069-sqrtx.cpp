class Solution {
public:
    int mySqrt(int x) {
        if(x == 1){
      return 1;
        }
        int st =0,end = x/2;long long mid=0;
        while(st<=end){

            mid = (st+end)/2;

            if(mid*mid == x){
                return mid;
            }
            else if((mid*mid)< x && ((mid+1)*(mid+1)) > x)
            return mid;
            else if(mid*mid < x){
              st = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return mid;
}
};