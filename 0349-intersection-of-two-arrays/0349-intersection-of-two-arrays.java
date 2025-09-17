class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> ans = new ArrayList<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
       int i=0,j=0;
       while(i<nums1.length && j < nums2.length){
          if(nums1[i] < nums2[j]){
            i++;
          }
          else if(nums1[i] == nums2[j]){ if(!ans.contains(nums1[i]))ans.add(nums1[i]);
            i++;j++;
          }
          else{
            j++;
          }
       }
       i=0;
       int[] ans1 = new int[ans.size()];
       for(int x:ans){
        ans1[i] = x;
        i++;
       }
       return ans1; 
    }
}