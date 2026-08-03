class Solution {

    void help(int idx ,int[] candidates, int target, List<List<Integer>> ans, List<Integer> temp){
         if(target<0 || idx == candidates.length){
            return;
        }
        if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }
       temp.add(candidates[idx]);
        help(idx,candidates, target-candidates[idx], ans , temp);
        temp.remove(temp.size()-1);
        help(idx+1,candidates, target, ans , temp);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
       List<List<Integer>> ans = new ArrayList<>();
       List<Integer> temp = new ArrayList<>();
       help(0,candidates,target,ans,temp);
       return ans;
    }
}