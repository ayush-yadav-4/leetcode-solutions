class Solution {
    public boolean helper(int[] nums, int days,int limit){
        int day =1,wt=0;
        for(int i=0;i<nums.length;i++){
          if(wt+nums[i] > limit){
            
            day+=1;
            wt = nums[i];

          }
          else{
            wt += nums[i];
          }

         if(day > days) return false;
        }

        if(day <= days) return true;
        return false;
    }
    public int shipWithinDays(int[] weights, int days) {
         int sum=0,maxi = 0;
        for(int i=0;i<weights.length;i++){
            sum += weights[i];
            maxi = Math.max(maxi,weights[i]);
        }

        int st = maxi,end = sum,ans=0;

        while(st <= end){
          int mid = (end+st)/2;
          if(helper(weights,days,mid)){
            ans = mid;
            end = mid-1;
          }
          else st = mid+1;
        }
        return ans;
    }
}