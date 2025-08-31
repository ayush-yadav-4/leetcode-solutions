class Solution {
    static final int MOD = 1_000_000_007;

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        int maxVal = 100000;

        // Step 1: Precompute prime scores
        int[] primeScore = new int[maxVal + 1];
        int[] spf = new int[maxVal + 1]; // smallest prime factor
        for (int i = 2; i <= maxVal; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxVal; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                    primeScore[j]++; // count distinct prime factor
                }
            }
        }

        // Step 2: Compute ps[i]
        int[] ps = new int[n];
        for (int i = 0; i < n; i++) {
            ps[i] = primeScore[nums.get(i)];
        }

        // Step 3: Compute left[i]
        int[] left = new int[n];
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!stack.isEmpty() && ps[stack.peek()] < ps[i]) {
                count += left[stack.pop()];
            }
            left[i] = count;
            stack.push(i);
        }

        // Step 4: Compute right[i]
        int[] right = new int[n];
        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!stack.isEmpty() && ps[stack.peek()] <= ps[i]) {
                count += right[stack.pop()];
            }
            right[i] = count;
            stack.push(i);
        }

        // Step 5: Build array of (val, count)
        long[][] arr = new long[n][2];
        for (int i = 0; i < n; i++) {
            long cnt = (long) left[i] * right[i];
            arr[i][0] = nums.get(i);
            arr[i][1] = cnt;
        }

        // Step 6: Sort by value descending
        Arrays.sort(arr, (a, b) -> Long.compare(b[0], a[0]));

        // Step 7: Greedily choose
        long ans = 1;
        for (int i = 0; i < n && k > 0; i++) {
            long val = arr[i][0];
            long cnt = arr[i][1];
            long take = Math.min((long) k, cnt);
            ans = (ans * modPow(val, take, MOD)) % MOD;
            k -= take;
        }

        return (int) ans;
    }

    private long modPow(long base, long exp, long mod) {
        long res = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
}
