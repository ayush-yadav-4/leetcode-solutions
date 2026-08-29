class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;
        Arrays.sort(nums);
        int curr = nums[0], ans = 1;
        int cnt = 1;
        for(int i=1;i<nums.length;i++){

             if (nums[i] == curr) {
                continue;  // ignore duplicates
            }
           if((curr+1) == nums[i]){
            cnt++;
           }
           else if(curr+1 != nums[i]){
            
            cnt = 1;
           }
           curr = nums[i];
           ans = Math.max(ans,cnt);
        }
        return ans;
    }
}