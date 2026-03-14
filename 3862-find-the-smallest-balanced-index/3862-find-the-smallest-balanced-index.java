class Solution {
    public int smallestBalancedIndex(int[] nums) {

        int n = nums.length;
        long LIMIT = (long)1e15;

        long[] suffix = new long[n + 1];
        suffix[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (suffix[i + 1] > LIMIT / nums[i])
                suffix[i] = LIMIT;
            else
                suffix[i] = suffix[i + 1] * nums[i];
        }

        long leftSum = 0;

        for (int i = 0; i < n; i++) {
            long rightProduct = suffix[i + 1];

            if (leftSum == rightProduct)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
}