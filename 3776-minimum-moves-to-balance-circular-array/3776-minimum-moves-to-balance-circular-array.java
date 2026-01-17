class Solution {
    public long minMoves(int[] nums) {
       int idx = -1,n = nums.length;
        long sum =0,need = 0;

        for(int i = 0;i<nums.length;i++){
            sum += nums[i];
            if(nums[i]<0){ idx = i; need = (long)nums[i];}
        }
        if(sum <0) return -1;
        if(idx == -1) return 0;
        long ans = 0;
        int left = idx, right = idx,step = 0;

        while(need<0){
             step++;
             left = (left - 1 + n)%n;
             right = (right + 1)%n;

             if(nums[left] > 0){
                long take = Math.min(-need,nums[left]);
                long cost = take * step;
                ans += cost;
                need += take;
             }
            
             if(need < 0 && nums[right] > 0){
                long take = Math.min(-need,nums[right]);
                long cost = take * step;
                ans += cost;
                need += take;
             }
        }

        return ans;
    }
}