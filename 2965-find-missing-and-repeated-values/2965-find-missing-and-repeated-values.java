class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] nums = new int[grid.length * grid[0].length];
        int id =0;
        for(int i =0;i<grid.length;i++){
            for(int j =0;j<grid[0].length;j++){
               nums[id++] = grid[i][j];
            }
        }
        int dup = 0; int mis = 0;
    Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
          int idx = Math.abs(nums[i]) - 1;
          if(nums[idx] < 0){
            dup = Math.abs(nums[i]);
            
           
          }
          else{
            nums[idx] = -nums[idx];
          }
        }

        for(int i=0;i<nums.length;i++){
          if(nums[i] > 0){
            mis = i+1;
            break;
          }
        }
        return new int[]{dup,mis};
    }
}