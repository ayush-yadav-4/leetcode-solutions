class Solution {

    void help(int idx , int[] nums,  List<List<Integer>> ans,List<Integer>temp){
        if(idx == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        if(idx >= nums.length) return;

        temp.add(nums[idx]);
        help(idx+1, nums,ans ,temp);
        temp.remove(temp.size()-1);
        help(idx+1, nums,ans ,temp);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer>temp = new ArrayList<>();
        List<List<Integer>>ans =  new ArrayList<>();
        help(0, nums, ans,temp);
        return ans;
    }
}