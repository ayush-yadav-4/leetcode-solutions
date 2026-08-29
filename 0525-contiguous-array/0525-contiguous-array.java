class Solution {
    public int findMaxLength(int[] nums) {
        int[] freq = new int[2];
        Map<Integer, Integer> mp = new HashMap<>();
        int ans = 0, r=0, l=0;
        int sum = 0;
        mp.put(0,-1);
        for(int i=0;i<nums.length;i++){
           if(nums[i] == 0) nums[i] = -1;
        }
        while(r < nums.length){
            sum += nums[r];

           if(mp.containsKey(sum)){
            ans = Math.max(ans , r - mp.get(sum));
           }
           else{
              mp.put(sum, r);
           }
          
          
           r++;
        }

        return ans;
    }
}