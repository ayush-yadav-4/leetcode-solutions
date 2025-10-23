class Solution {
    void helper( List<List<Integer>> ans, List<Integer>temp,int target,int[] nums,int idx){
        if(idx == nums.length){
            if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        return;
        }
        else if(target<0) return;
        else if(target ==0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        temp.add(nums[idx]);
        helper(ans,temp,target-nums[idx],nums,idx);
        temp.remove(temp.size()-1);
        helper(ans,temp,target,nums,idx+1);
        
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer>temp = new ArrayList<>();

        helper(ans,temp,target,candidates,0);
        return ans;
    }
}