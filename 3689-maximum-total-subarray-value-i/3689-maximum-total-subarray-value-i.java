class Solution {
    public long maxTotalValue(int[] nums, int k) {
        long ans = 0;
     
      long mini = Long.MAX_VALUE,maxi = Long.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            
                maxi = Math.max(maxi,nums[i]);
                mini = Math.min(mini,nums[i]);
                
            
          
            
        }

    
    
        
         return k * (maxi - mini);
    }
}