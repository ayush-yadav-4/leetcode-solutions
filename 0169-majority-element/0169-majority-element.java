class Solution {
    public int majorityElement(int[] nums) {
        int elem = 0, cnt = 0;
        for(int i=0;i<nums.length;i++){
            if(cnt==0){
                 cnt = 1; elem = nums[i];
            }
            else if(elem == nums[i])cnt++;
            else cnt--;
        }

        return elem;
    }
}