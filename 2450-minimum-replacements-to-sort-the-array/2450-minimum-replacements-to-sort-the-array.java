class Solution {
    public long minimumReplacement(int[] nums) {
        long ops = 0;
        int n = nums.length;
        
        // last element is always fine
        long prev = nums[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= prev) {
                prev = nums[i];
            } else {
                // need to split nums[i]
                long k = (nums[i] + prev - 1) / prev; // ceil(nums[i]/prev)
                ops += (k - 1);
                prev = nums[i] / k; // new "allowed" max value
            }
        }
        
        return ops;
    }
}
