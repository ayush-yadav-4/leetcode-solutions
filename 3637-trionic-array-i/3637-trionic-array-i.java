class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        if (n < 4) return false;

        int i = 1;

        // 1️⃣ strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1) return false; // no increasing part

        // 2️⃣ strictly decreasing
        int decStart = i;
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == decStart) return false; // no decreasing part

        // 3️⃣ strictly increasing
        int incStart = i;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == incStart) return false; // no final increasing part

        return i == n;
    }
}
