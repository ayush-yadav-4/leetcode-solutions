class Solution {
    void swap(int a, int b, List<Integer>ls){
        int temp = ls.get(a);
        ls.set(a,ls.get(b));
        ls.set(b,temp);
        return;
    }
    void helper(List<Integer> nums, int idx, int n, List<List<Integer>>ans){

        if(idx == n){
            
            ans.add(new ArrayList<>(nums));
            return;
        }
        for(int i=idx;i<nums.size();i++){
           swap(idx,i,nums);
           helper(nums,idx+1,n,ans);
           swap(idx,i,nums);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ls = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
          ls.add(nums[i]);
        }
         helper(ls,0,nums.length,ans);
         return ans;
    }
}