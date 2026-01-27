class Solution {
    public long splitArray(int[] nums) {
       Boolean[] pre = new Boolean[nums.length];
       Boolean[] suf = new Boolean[nums.length];
       long sum =0,ans = Long.MAX_VALUE-1;
       long[] prefix = new long[nums.length];
       for(int a: nums){
        sum += a;
       }int n = nums.length;
        pre[0] = true;
        suf[n-1] = true;
        prefix[0] = (long)nums[0];
       for(int i=1;i<nums.length;i++){
          prefix[i] = prefix[i-1] + nums[i];
         
            pre[i] = pre[i-1] && (nums[i] > nums[i-1]);
          

         
            
          
       }
       for(int i = n-2;i>=0;i--){
          suf[i] = suf[i+1] && (nums[i] > nums[i+1]);
       }

       for(int i=0;i<nums.length-1;i++){
            if(pre[i] == true && suf[i+1] == true){
               long  a = prefix[i];
               long b = sum - prefix[i];
               ans = Math.min(ans,Math.abs(a-b));
            }
       }

       return (ans == Long.MAX_VALUE-1) ? -1:ans ;
    }
}