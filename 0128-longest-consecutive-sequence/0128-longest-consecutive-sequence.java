class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length <=1) return nums.length;
       Arrays.sort(nums);
      int ans =0,cnt = 1;
       for(int i=0;i<nums.length-1;i++){
        if(nums[i] == nums[i+1]){
            continue;
        }
        else if(nums[i] == (nums[i+1]-1)){
          cnt++;
        }
        else{
          ans = Math.max(ans, cnt);
          cnt = 1;
        }
    
       }
       return Math.max(ans, cnt);
    }
}