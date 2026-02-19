class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        
       int cnt = 0;
        for(int i=0;i<nums.length;i++){
             //if(nums[i] == target) cnt++;
          Map<Integer, Integer>mp = new HashMap<>();
          for(int j=i;j<nums.length;j++){
              mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
             
              if(mp.containsKey(target) && mp.get(target) > (j-i+1)/2){
                cnt++;
              }
          }
        }

        return cnt;
    }
}