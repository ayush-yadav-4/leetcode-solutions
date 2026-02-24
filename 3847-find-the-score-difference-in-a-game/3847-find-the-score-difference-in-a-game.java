class Solution {
    void swap(int a , int b){
       int temp = a;
       a = b;
       b = temp;
    }
    public int scoreDifference(int[] nums) {
        int onesum = 0; int twosum = 0, idx =1;
        boolean one =true;
        boolean two = false;
        for(int i=0;i<nums.length;i++){
           
           

          if(nums[i] % 2 != 0){
              one = !one;
              two = !two;
          }
           if(i == ((6*idx) - 1)){
            idx++;
              one = !one;
              two = !two;
          }
          if(one) onesum += nums[i];
           else twosum += nums[i];

        }
        return onesum - twosum;
    }
}