class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        // Step 1: find gcd of numsDivide
        int g = numsDivide[0];
        for (int i = 1; i < numsDivide.length; i++) {
            g = gcd(g, numsDivide[i]);
        }

        // Step 2: sort nums
        Arrays.sort(nums);

        // Step 3: find smallest divisor
        for (int i = 0; i < nums.length; i++) {
            if (g % nums[i] == 0) {
                return i;  // all elements before i are deleted
            }
        }

        return -1;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
