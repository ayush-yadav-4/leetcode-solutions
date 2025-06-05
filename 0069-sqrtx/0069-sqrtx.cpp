class Solution {
public:
    int mySqrt(int x) {
     if(x == 1) return 1;
     if(x == 0) return 0;
     long long  num=0;
    int ans=1;
     long long st = 1,end = x;
     while(st <= end){
      long long mid = st + (end-st)/2;
     long long num = (mid * mid);
      if(num == x) return mid;
      else if(num > x) end = mid-1;
      else{ 
        ans = mid;
        st = mid + 1;}
     }
     return ans;
}
};