class Solution {
public:
bool Valid(vector<int>& weights, int days,int mid){
   int total =0,day=1;
  for(int i=0;i<weights.size();i++){
       if(weights[i]> mid) return false;
         if(total + weights[i]<= mid){
            total += weights[i];
         }else{
            day++;
            total = weights[i];
         }
        }

        if(days >= day) return true;

        return false;
  
}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum =0;
        for(int i=0;i<weights.size();i++){
         sum += weights[i];
        }
        int st = 1,end = sum,mid =0,ans =-1;
        while(st<=end){

         mid = st+(end-st)/2;
         if(Valid(weights,days,mid)){
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