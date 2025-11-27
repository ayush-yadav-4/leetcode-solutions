class Solution {
    public int removeDuplicates(int[] nums) {
        int st = 0, sec = 0,cnt = 0;
        while(sec <= nums.length){
           while(sec < nums.length && nums[st] == nums[sec]) sec++;
           if(sec == nums.length) break;
           st++;
           nums[st] = nums[sec];
           cnt++;
        }
       return cnt+1;
    }
}