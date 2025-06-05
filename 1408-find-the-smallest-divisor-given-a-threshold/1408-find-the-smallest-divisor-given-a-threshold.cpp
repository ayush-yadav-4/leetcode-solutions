class Solution {
public:
bool Valid(vector<int>& nums, int th ,int mid){
    long long ans=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]%mid == 0){
           ans += nums[i]/mid;
        }
        else if(nums[i]%mid != 0) ans += (nums[i]/mid) + 1;
       
       if(ans>th) return false;
     }
     return true;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        
            int maxi =INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
          maxi = max(maxi,nums[i]);
           mini = min(mini,nums[i]);
        }
        int st = 1,end = maxi,mid =0,ans =-1;
        while(st<=end){

         mid = st+(end-st)/2;
         if(Valid(nums,threshold,mid)){
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