class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer>mp = new HashMap<>();
       int sum =0, cnt =0;
 
       for(int i=0;i<nums.length;i++){
          sum += nums[i];
          if(sum == k)cnt++;
          int find = sum -k;
          if(mp.containsKey(find)){
            cnt += mp.get(find);
          }

          mp.put(sum ,mp.getOrDefault(sum,0)+1);
    
          
       }
       return cnt;
    }
}