class Solution {
    public boolean partitionArray(int[] nums, int k) {
        int elem = nums.length,dupli = 1;

        if(elem%k != 0) return false;
        int groups = elem/k;

        Map<Integer,Integer>mp = new HashMap<>();

        for(int i=0;i<nums.length;i++){
          mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }

        for(Map.Entry<Integer,Integer>m : mp.entrySet()){
           if(m.getValue() > groups) return false;
        }

        // if(mp.size() >= k){
        //    return true;
        // }
        return true;
    }
}