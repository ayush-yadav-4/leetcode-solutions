class Solution {
    void helper( Set<List<Integer>>st,List<Integer>temp,int[]nums,int idx){

        if(idx == nums.length){
          List<Integer>copy = new ArrayList<>(temp);
          Collections.sort(copy);
          st.add(copy);
          return;
        }

        temp.add(nums[idx]);
        helper(st,temp,nums,idx+1);
        temp.remove(temp.size()-1);
        helper(st,temp,nums,idx+1);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Set<List<Integer>>st = new HashSet<>();
        helper(st,new ArrayList<>(),nums,0);
        return new ArrayList<>(st);
    }
}