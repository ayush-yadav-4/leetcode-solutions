class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1); Arrays.sort(nums2);
       Set<Integer>ans = new HashSet<>();
       
       int i=0; int j=0;
        while(i< nums1.length && j < nums2.length){
          if(nums1[i] == nums2[j]){
            ans.add(nums1[i]);
            i++; j++;
          }
          else if(nums1[i] < nums2[j]) i++;
          else j++;
        }
        int k =0;
        int[] ans1 = new int[ans.size()];
        for(int elem : ans){
           ans1[k++] = elem;
        }
        return ans1;
    }
}