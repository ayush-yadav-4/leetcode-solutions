class Solution {

    void helper(int[] candidates, int target, int n, int idx , List<Integer> temp ,List<List<Integer>>ans){
        if(target < 0) return;
       if(idx == n){
        if(target == 0){
        ans.add(new ArrayList<>(temp));
        return;
        }
        return;
       }
       
      temp.add(candidates[idx]);
       helper(candidates, target-candidates[idx] , n , idx,temp,ans );
       temp.remove(temp.size()-1);
       helper(candidates, target, n , idx+1,temp,ans);


    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        helper(candidates, target,candidates.length,0,temp,ans);
        return ans;
    }
}