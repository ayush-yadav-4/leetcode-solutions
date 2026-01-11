class Solution {
    public int centeredSubarrays(int[] nums) {
         int cnt =0;
          Map<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int sum = 0;
           
            mp.clear();
            for(int j=i;j<nums.length;j++){
             sum += nums[j];
               mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);
              if(mp.containsKey(sum)){
                cnt++;
             }
            
            
            
            }
           
        }
        
        return cnt;
    }
}
