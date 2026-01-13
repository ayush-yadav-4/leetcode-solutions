class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] arr = new int[nums1.length + nums2.length];
        int i=0,j=0,k=0;
        while(i<nums1.length && j < nums2.length){
             if(nums1[i]<nums2[j]){
                arr[k++] = nums1[i++];
             }
             else{
                arr[k++] = nums2[j++];
             }
        }

        while(i<nums1.length){
            arr[k++] = nums1[i++];
        }
         while(j<nums2.length){
            arr[k++] = nums2[j++];
        }
      
        int mid = (arr.length-1)/2;
        double ans = 0;
        if(arr.length%2 == 0){
            
            ans = (double)((arr[mid] + arr[mid+1])/2.000);
        }
        else{
            
            ans = (double)(arr[mid]);
        }
        return ans;
    }
}