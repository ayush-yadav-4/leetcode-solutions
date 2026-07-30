class Solution {

    boolean check(int[] nums, int threshold, long mid){
        int sum =0;

        for(int i=0;i<nums.length;i++){
           if(nums[i]%mid == 0){
            sum += nums[i]/mid;
           }
           else{
            sum +=( nums[i]/mid) + 1;
           }

           if(sum > threshold) return false;
        }

        if(sum <= threshold) return true;
        return false;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        
        long st = 1, end =0;
        int ans =0;

        for(int i=0;i<nums.length;i++){
          end += nums[i];
        }

        while(st<=end){
          long mid = st + (end-st)/2;

          if(check(nums,threshold,mid )){
            ans = (int)mid;
            end = mid-1;
          }
          else{
            st = mid+1;
          }
        }

      return ans;
    }
}