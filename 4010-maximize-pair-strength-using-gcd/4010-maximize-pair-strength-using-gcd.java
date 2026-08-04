class Solution {

    long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long find(int a, int b) {
        long g = gcd(a, b);
        return (1L * a * b) / (g * g);
    }

    public long maxPairStrength(int[] nums) {
        long ans = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                ans = Math.max(ans, find(nums[i], nums[j]));
            }
        }

        return ans;
    }
}