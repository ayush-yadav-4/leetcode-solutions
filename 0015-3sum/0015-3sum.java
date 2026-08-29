class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
         Arrays.sort(nums);
         List<List<Integer>> ans = new ArrayList<>();
         Set<List<Integer>>s = new HashSet<>();
        for(int i=0;i<nums.length;i++){
           int st = i + 1, end = nums.length -1;
          while(st < end){
            int sum = nums[i] + nums[st] + nums[end];
            if(sum == 0){
                List<Integer> ls = new ArrayList<>();
                ls.add(nums[i]);
                ls.add(nums[st]);
                ls.add(nums[end]);
                s.add(ls);
                end--;
            }
            else if(sum > 0){
                end--;
            }
            else st++;
          }
        }

        for(List<Integer> ls: s){
           ans.add(ls);
        }
     return ans;
    }
}