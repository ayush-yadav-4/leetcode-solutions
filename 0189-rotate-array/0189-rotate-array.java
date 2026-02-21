
class Solution{
    void Rotate(int st , int end , int[] nums){
       while(st<end){
         int temp = nums[st];
         nums[st] = nums[end];
         nums[end] = temp;
         st++;
         end--;
       }
    }
 public void rotate(int[]nums,int k){
    if(nums.length == 1 ) return;
    k = k % nums.length;
    Rotate(0, nums.length-k-1,nums);
   Rotate(nums.length-k, nums.length-1, nums);
   
   Rotate(0, nums.length-1,nums);
 }
}
