class Solution {
    public long countPairs(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        long result = 0;

        for (int num : nums) {
            int g = gcd(num, k);

            // check against all previous gcds
            for (int g2 : freq.keySet()) {
                if ((long) g * g2 % k == 0) {
                    result += freq.get(g2);
                }
            }

            // add current gcd to map
            freq.put(g, freq.getOrDefault(g, 0) + 1);
        }

        return result;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}
