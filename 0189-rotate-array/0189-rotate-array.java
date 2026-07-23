
class Solution{
 void swap(int[] nums , int st, int end){
   while(st<=end){
    int a = nums[st];
    nums[st] = nums[end];
    nums[end] = a;
    st++;
    end--;
   }
 }
 public void rotate(int[]nums,int k){
    k = k % nums.length;
    int n = nums.length;
    swap(nums,0,n-k-1);
    swap(nums,n-k,nums.length-1);
    swap(nums,0,nums.length-1);
 }
}
