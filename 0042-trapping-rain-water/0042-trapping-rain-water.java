class Solution {
    public int trap(int[] nums) {
        Stack<Integer>st = new Stack<>();
        int[] nge = new int[nums.length];
        int[] pge = new int[nums.length];
        int maxi1 = 0, maxi2 = 0;
        for(int i=0;i<nums.length;i++){
            maxi1 = Math.max(maxi1, nums[i]);
            maxi2 = Math.max(maxi2,nums[nums.length-i-1]);
           pge[i] = Math.max(maxi1, nums[i]);
           nge[nums.length-i-1] = Math.max(maxi2, nums[nums.length-i-1]);
        }
       
        int sum =0;
        for(int i=0;i<nums.length;i++){
          
        
            int h = Math.min(pge[i], nge[i]);
            
            int num =  h - nums[i];
           if(num > 0) sum += num;
        

        }

        return sum;



    }
}