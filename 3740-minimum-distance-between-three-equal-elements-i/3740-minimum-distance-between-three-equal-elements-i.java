class Solution {
    public int minimumDistance(int[] nums) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
      int ans = 10000000;
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(nums[i]) && mp.get(nums[i]).size()>=2){
                int n = mp.get(nums[i]).size();
                List<Integer> ls = mp.get(nums[i]);
                Collections.sort(ls);
              ans = Math.min(ans, Math.abs(ls.get(n-1) - ls.get(n-2)) + Math.abs(ls.get(n-1) - i) + Math.abs(i - ls.get(n-2)));
            }
            
                mp.putIfAbsent(nums[i],new ArrayList<>());
                mp.get(nums[i]).add(i);
            
        }
        if(ans == 10000000) return -1;
        return ans;
    }
}