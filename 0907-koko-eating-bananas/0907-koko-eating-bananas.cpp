class Solution {
public:
bool check(vector<int>& piles, int h,int mid){
   int ans = 0;
   for(int it : piles){
      if(it % mid == 0){
        ans += (it/mid);
      } 
      else{
        ans += (it/mid)+1;
      }
      if(ans > h) return false;
   }
   if(ans > h) return false;
   return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int  st =1,end = 0,mid=0;
        int ans = 0;

        for(int it: piles){
          end += it;
        }
        while(st<=end){
           mid = (st + (end-st)/2);

           if(check(piles,h,mid)){
            ans = mid;
            end = mid-1;
           }
           else{
            st = mid+1;
           }
        }
        return ans;
    }
};