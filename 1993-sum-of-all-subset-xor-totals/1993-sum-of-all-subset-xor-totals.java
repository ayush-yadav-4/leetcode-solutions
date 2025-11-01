class Solution {
    public int subsetXORSum(int[] nums) {
        return dfs(nums, 0, 0);
    }

    private int dfs(int[] nums, int index, int curr_xor) {
        if (index == nums.length) return curr_xor;

        int with_curr = dfs(nums, index + 1, curr_xor ^ nums[index]);
        int without_curr = dfs(nums, index + 1, curr_xor);

        return with_curr + without_curr;
    }
}