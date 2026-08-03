class Solution {
    void swap(int a, int b, int[] nums){
      int temp = nums[a];
      nums[a] = nums[b];
      nums[b] = temp;
    }
    void help(int idx , int[] nums ,List<int[]> temp,List<List<Integer>> ans ){
     
     if(idx == nums.length){
       List<Integer> t =new ArrayList<>();

       for(int a: nums){
         t.add(a);
       }
       ans.add(new ArrayList<>(t));
        return;
     }

     for(int i=idx;i<nums.length;i++){
       swap(idx,i,nums);
      
       help(idx+1,nums,temp,ans);
       swap(idx,i,nums);
      
     }
     return;
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<int[]> temp = new ArrayList<>();
        help(0,nums,temp,ans);
        return ans;
    }
}