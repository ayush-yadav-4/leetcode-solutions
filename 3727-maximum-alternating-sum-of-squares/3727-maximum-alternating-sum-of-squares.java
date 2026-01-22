class Solution {
//   long ans = 0;
//   long solve(int[] nums){
//       long sum = 0;

//       for(int i=0;i<nums.length;i++){
//           if(i%2 == 0){
//             sum += (nums[i] * nums[i]);
//           }
//           else{
//             sum -= (nums[i] * nums[i]);
//           }
//       }

//       return sum;
//   }
//    void swap(int a , int b, int[] nums){
//       int temp = nums[a];
//       nums[a] = nums[b];
//       nums[b] = temp;
//    }
//     void helper(int idx,int[] nums,Long[] dp){
//         if(idx == nums.length) return;
//          ans = Math.max(ans,solve(nums));
//          if(dp[idx]!= -1) return;
//         for(int i = idx;i<nums.length;i++){
//            swap(idx,i,nums);
//            helper(idx+1,nums,dp);
//            swap(idx,i,nums);
//         }
//         dp[idx] = ans;

//     }
    public long maxAlternatingSum(int[] nums) {
        // Long[] dp = new Long[nums.length];
        // Arrays.fill(dp,(long)-1);
        // helper(0,nums,dp);
        // return ans;

        Long[] arr = new Long[nums.length];
        for(int i=0;i<nums.length;i++){
            arr[i] =(long)( nums[i] * nums[i]);
        }
        Arrays.sort(arr);
        int i =0,j = nums.length-1;
       long ans = 0;
        while(i<=j){
            if(i == j){
                ans += arr[i];
                return ans;
            }

            ans += arr[j--];
            ans-= arr[i++];
        }
        return ans;
    }
}