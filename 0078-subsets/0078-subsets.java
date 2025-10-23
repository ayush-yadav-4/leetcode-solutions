class Solution {
    void helper(List<List<Integer>> ans,List<Integer>temp,int idx , int[] nums){
        if(idx == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        temp.add(nums[idx]);
        helper(ans,temp,idx+1,nums);
        temp.remove(temp.size()-1);
        helper(ans,temp,idx+1,nums);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer>temp = new ArrayList<>();
        helper(ans,temp,0,nums);
        return ans;
    }
}