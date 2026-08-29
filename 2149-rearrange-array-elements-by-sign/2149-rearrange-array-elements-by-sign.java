class Solution {
    public int[] rearrangeArray(int[] nums) {
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        

        for(int i=0;i<nums.length;i++){
         if(nums[i] < 0) a.add(nums[i]);
         else b.add(nums[i]);
        } 
        int idx1 = 0,idx2 = 0;
       for(int i=0;i<nums.length;i++){
          if(i%2 != 0){
            nums[i] = a.get(idx1++);
          }
          else nums[i] = b.get(idx2++);
       }
       return nums;
    }
}