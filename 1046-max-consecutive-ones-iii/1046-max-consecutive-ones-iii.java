class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = 0,f = 0,end = 0,zero = 0;
        // while(end < nums.length){
        //   if(k == 0 && nums[end] == 0){
        //    while(k <= 0){
        //     if(nums[f] == 0){
        //         k++;
        //     }
        //     f++;
        //    }
        //   }
        //     if(nums[end] == 0){
        //     k--; 
        //    }
            
        //     ans = Math.max(ans,end - f +1);

        //     end++;
           
         
        // }

        while(end < nums.length){
             if(nums[end] == 0) zero++;
              if(zero > k){
                if(nums[f] == 0){
                    zero--;
                }
                f++;
              }
              if(zero<=k){
                ans = Math.max(ans,end-f+1);
              }
              end++;
             
        }
        return ans;
    }
}