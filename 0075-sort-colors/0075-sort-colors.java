class Solution {

    void swap(int a , int b, int[] nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    public void sortColors(int[] nums) {
        int st = -1; int mid = 0; int end = nums.length-1;

        while(mid <= end){
           if(nums[mid] == 0){
            st++;
            swap(st, mid, nums);
            mid++;
            
            
           }
           else if(nums[mid] == 2){
            swap(mid, end, nums);
            end--;
           }
           else mid++;
        }
    }
}