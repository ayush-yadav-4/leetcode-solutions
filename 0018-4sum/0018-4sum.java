class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

         if(target >= Integer.MAX_VALUE || target <= Integer.MIN_VALUE) return new ArrayList<>();
        Set<List<Integer>>ans_set = new HashSet<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length-3;i++){
             if(i>0 && nums[i] == nums[i-1])continue;
            for(int j = i+1;j<nums.length-2;j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;
                   int st = j+1,end = nums.length-1;
                   
                while(st<end){
                  long sum = (long) nums[i] + nums[j] + nums[st] + nums[end];
                  if(sum == Integer.MAX_VALUE || sum == Integer.MIN_VALUE) return new ArrayList<>();
                  if(sum == target){
                    List<Integer>temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[st]);
                    temp.add(nums[end]);
                    ans_set.add(temp);
                     while (st < end && nums[st] == nums[st + 1]) st++;
                        while (st < end && nums[end] == nums[end - 1]) end--;
                    st++;end--;
                  }
                  else if(sum > target){
                    end--;
                  }
                  else{
                    st++;
                  }
                }
            }
        }

        List<List<Integer>>ans = new ArrayList<>(ans_set);
        return ans;


    }
}