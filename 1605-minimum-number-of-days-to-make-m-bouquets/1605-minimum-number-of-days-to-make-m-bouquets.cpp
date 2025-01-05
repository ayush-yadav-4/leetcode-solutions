class Solution {
public:
bool Valid(vector<int>& bloomDay, int m, int k,int mid){
  int cnt =0,total=0;
    for(int i=0;i<bloomDay.size();i++){
       if(bloomDay[i]<=mid){
        cnt++;
       }else{
        total += cnt/k;
        cnt =0;
       }
    }
    total += cnt/k;

    if(total>=m) return true;
   return false;

}
    int minDays(vector<int>& bloomDay, int m, int k) {
         int maxi =INT_MIN,mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
          maxi = max(maxi,bloomDay[i]);
           mini = min(mini,bloomDay[i]);
        }
        int st = mini,end = maxi,mid =0,ans =-1;
        while(st<=end){

         mid = st+(end-st)/2;
         if(Valid(bloomDay,m,k,mid)){
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