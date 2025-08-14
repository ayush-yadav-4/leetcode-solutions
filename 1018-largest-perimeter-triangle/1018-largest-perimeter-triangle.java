import java.util.Arrays;

class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums); // Sort in ascending order
        // Start from the largest side
        for (int i = nums.length - 1; i >= 2; i--) {
            int a = nums[i - 2];
            int b = nums[i - 1];
            int c = nums[i];
            if (a + b > c) {
                return a + b + c; // Largest perimeter found
            }
        }
        return 0; // No valid triangle
    }
}
