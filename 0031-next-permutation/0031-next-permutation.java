class Solution {
    void reverse(int i, int j,int[] nums){
      while(i<j){
                    int temp = nums[i];
             nums[i] = nums[j];
             nums[j] = temp;
             i++; j--;
      }
    }
    public void nextPermutation(int[] nums) {
        
        int i = nums.length-2;
        int n = nums.length;
        int j = 0;
        while(i>=0 && nums[i] >= nums[i+1]){
          i--;
        }
        if(i>=0){
              j = n-1;
             while(j>= 0 && nums[j] <= nums[i]){
               j--;
             }
             int temp = nums[i];
             nums[i] = nums[j];
             nums[j] = temp;
        }

        reverse(i+1,n-1,nums);
        return;
    }
}