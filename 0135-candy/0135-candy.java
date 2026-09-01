class Solution {
    public int candy(int[] nums) {
        int ans = 0;
        int last = -1;
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);

        for(int i=1;i<nums.length;i++){
          if(nums[i] > nums[i-1]){
            left[i] = left[i-1]+1;
          }
          else{
            left[i]= 1;
          }
        }
        for(int i=nums.length-2;i>=0;i--){
          if(nums[i] > nums[i+1]){
            right[i] = right[i+1]+1;
          }
          else{
           right[i]= 1;
          }
        }

        for(int i=0;i<nums.length;i++){
        ans += Math.max(left[i],right[i]);
        }

        return ans;
    }
}