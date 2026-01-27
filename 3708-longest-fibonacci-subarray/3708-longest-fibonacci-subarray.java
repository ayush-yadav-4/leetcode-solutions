class Solution {
    public int longestSubarray(int[] nums) {
        if(nums.length <= 2) return nums.length;
        if(nums.length == 2) return 2;
        int cnt = 0;
        
        for(int i=2;i<nums.length;i++){
           if(nums[i] == (nums[i-1] + nums[i-2])){
            long a = nums[i-2],b = nums[i-1];
            int idx = i,ans = 0;
            long sum =0;
             while(idx <nums.length){
            sum = a + b;
               a = b;
               b = sum;
               if(sum != nums[idx]) break;
               idx++;
               ans++;
             }
            
              cnt = Math.max(cnt,ans);
           }
        }

        return (cnt + 2);
    }
}