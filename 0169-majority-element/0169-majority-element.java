class Solution {
    public int majorityElement(int[] nums) {
         int cnt = 0, elem = 0;
        for(int i=0;i<nums.length;i++){
           if(cnt == 0){
             elem = nums[i];
             cnt = 1;
           }
           else if(nums[i] == elem){
            cnt++;
           }
           else{
            cnt--;
           }
        }

        return elem;
    }
}