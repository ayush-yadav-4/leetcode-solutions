class Solution {
    public int minLength(int[] nums, int k) {
        Map<Integer,Integer>mp = new HashMap<>();
         int sum = 0,i=0,j=0;
         int ans = (int)1e7;
        while(i<nums.length){
              if(nums[i] >= k) return 1;
               mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
               if(mp.get(nums[i]) == 1){
                sum += nums[i];
               }

               while(sum >= k){
                  ans = Math.min(ans,i-j+1);

                  mp.put(nums[j],mp.get(nums[j])-1);
                  if(mp.get(nums[j]) == 0){
                    sum -= nums[j];
                    mp.remove(nums[j]);
                  }
                  j++;
               }
               i++;
            }
            if(ans == (int)1e7) return -1;
        return ans;
    }
}