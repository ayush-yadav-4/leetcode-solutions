class Solution {

    void swap(int i, int j, int[] nums1, int[] nums2){
       int temp = nums1[i];
       nums1[i] = nums2[j];
       nums2[j] = temp;
    }
    public void merge(int[] nums1, int m, int[] nums2, int n) {
       int i = m-1; int j = n-1; int k = m + n -1;
       while(i>= 0 && j >=0){
         if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
            
         }
         else{
         nums1[k] = nums2[j];
         j--;
         
         }
         k--;
       }
       while(j>=0){
         nums1[k--] = nums2[j--]; 
       }
        return;
    }
}