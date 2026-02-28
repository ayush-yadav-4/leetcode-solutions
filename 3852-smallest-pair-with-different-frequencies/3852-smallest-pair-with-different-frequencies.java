class Solution {
    public int[] minDistinctFreqPair(int[] nums) {
        if(nums.length <=2) return new int[]{-1,-1};
        Arrays.sort(nums);
       Map<Integer, Integer>mp = new LinkedHashMap<>();
      
       for(int i=0;i<nums.length;i++){
          mp.put(nums[i], mp.getOrDefault(nums[i], 0)+1);
       }
       int[] ans =  new int[2];
       ans[0] = nums[0];
       int freq = mp.get(nums[0]);
       for(Map.Entry<Integer, Integer> m : mp.entrySet()){
           if(m.getValue() != freq){
             ans[1] = m.getKey();
             break;
           }
        }
        if(ans[1] == 0) return new int[]{-1,-1};
        return ans;

    }
}