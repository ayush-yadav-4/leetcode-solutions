class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer>mp = new HashMap<>();
       int sum =0, cnt =0, r = 0 , l = 0;
  
       while(r<nums.length){
         
          sum += nums[r];
          int find = sum - k;
          if(sum == k) cnt++;
          if(mp.containsKey(find)){
             cnt += mp.get(find);
          }
           mp.put(sum, mp.getOrDefault(sum, 0) + 1);
          r++;
       }
       return cnt;
    }
}