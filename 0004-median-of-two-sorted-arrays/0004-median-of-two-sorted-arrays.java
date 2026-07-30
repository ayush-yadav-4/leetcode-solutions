class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
     int[] nums = new int[nums1.length + nums2.length];
     int st1 = 0 , st2 = 0, k=0;
     while(st1 < nums1.length && st2 < nums2.length){
        if(nums1[st1] <= nums2[st2]){
            nums[k++] = nums1[st1++];
        }
        else{
           nums[k++] = nums2[st2++];
        }
     }

     while(st1 < nums1.length){
       nums[k++] = nums1[st1++];
     }
     while(st2 < nums2.length){
       nums[k++] = nums2[st2++];
     }

     if(nums.length%2 == 0){
       return (double)(nums[nums.length/2] + nums[(nums.length/2)-1])/2;
     }

     return (double)nums[nums.length/2];
    }
}