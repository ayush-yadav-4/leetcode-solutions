

class Solution {

    public static void helper(List<List<Integer>> ans, List<Integer> temp, int[] nums, int target, int idx) {
        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (idx == nums.length || target < 0) {
            return;
        }

        // include nums[idx]
        temp.add(nums[idx]);
        helper(ans, temp, nums, target - nums[idx], idx); // stay at same idx (can reuse element)
        temp.remove(temp.size() - 1);

        // exclude nums[idx] and move to next
        helper(ans, temp, nums, target, idx + 1);
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(ans, temp, nums, target, 0);
        return ans;
    }

    // For testing
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {2, 3, 6, 7};
        int target = 7;
        System.out.println(sol.combinationSum(nums, target));
    }
}
