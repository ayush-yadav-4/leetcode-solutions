class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
         Arrays.sort(nums);
         List<List<Integer>> ans = new ArrayList<>();
         Set<List<Integer>>s = new HashSet<>();

         for(int j=0;j<nums.length;j++){
             for(int i=j+1;i<nums.length;i++){
           int st = i + 1, end = nums.length -1;
           if(st>=nums.length || end>= nums.length) continue;
          while(st < end){
            long sum = 0; sum += nums[i];
            sum += nums[j];
            sum+= nums[st]; 
            sum+= nums[end];
            if(sum == (long)target){
                List<Integer> ls = new ArrayList<>();
                ls.add(nums[i]);
                 ls.add(nums[j]);
                ls.add(nums[st]);
                ls.add(nums[end]);
                s.add(ls);
                st++;
                end--;
            }
            else if(sum > (long)target){
                end--;
            }
            else st++;
          }
        }

         }
        

        for(List<Integer> ls: s){
           ans.add(ls);
        }
     return ans;
    }
}