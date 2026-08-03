class Solution {
    void help(int idx , int[] nums,  List<List<Integer>> ans,List<Integer>temp, Set<List<Integer>> st){
        if(idx == nums.length){
           
            st.add(new ArrayList<>(temp));
            return;
        }
        if(idx >= nums.length) return;

        temp.add(nums[idx]);
        help(idx+1, nums,ans ,temp,st);
        temp.remove(temp.size()-1);
        help(idx+1, nums,ans ,temp,st);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer>temp = new ArrayList<>();
        List<List<Integer>>ans =  new ArrayList<>();
        Set<List<Integer>> st = new HashSet<>();
        help(0, nums, ans,temp,st);
        for(List<Integer> l: st){
         ans.add(l);
        }
        return ans;
    }
}