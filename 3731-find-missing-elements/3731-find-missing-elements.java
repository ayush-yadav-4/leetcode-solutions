class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> ls = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();

        int mini = 100000,maxi =0;

        for(int i=0;i<nums.length;i++){
            mini = Math.min(mini,nums[i]);
            maxi = Math.max(nums[i],maxi);
            ls.add(nums[i]);

        }
        for(int j = mini;j<=maxi;j++){
           if(!ls.contains(j)){
            ans.add(j);
           }
        }
        return ans;
    }
}