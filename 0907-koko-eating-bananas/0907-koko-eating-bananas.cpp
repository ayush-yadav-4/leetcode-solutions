class Solution {
public:
bool check(vector<int>& piles, int h,int mid){
    long long int ans = 0;
   for(int i=0;i<piles.size();i++){
        
          if(piles[i]%mid == 0){
            ans += piles[i]/mid;
          }else  ans += (piles[i]/mid) + 1;          
         }
         if(ans > h) return false;
         return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
          int st = 1,end=0,ans=0,mid=0;
         for(int i=0;i<piles.size();i++){
           end = max(end, piles[i]);          
         }
         
         while(st<=end){
            mid = st + (end-st)/2;
            if(check(piles,h,mid)){
                ans = mid;
                end = mid-1;
            }
            else st = mid+1;
         } 
         return ans;          
    }                                       
};