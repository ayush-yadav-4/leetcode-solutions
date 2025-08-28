class Solution {
    public long kMirror(int k, int n) {
        long sum = 0;
        int count = 0;
        int length = 1; // number of digits in base-10 palindrome

        while (count < n) {
            // Generate all base-10 palindromes of this length
            for (long p : generatePalindromes(length)) {
                if (isPalindromeInBase(p, k)) {
                    sum += p;
                    count++;
                    if (count == n) return sum;
                }
            }
            length++;
        }
        return sum;
    }

    // Generate all palindromes of given length in base-10
    private List<Long> generatePalindromes(int length) {
        List<Long> res = new ArrayList<>();
        int half = (length + 1) / 2;
        long start = (long) Math.pow(10, half - 1);
        long end = (long) Math.pow(10, half);

        for (long i = start; i < end; i++) {
            String left = Long.toString(i);
            String right = new StringBuilder(left.substring(0, length % 2 == 0 ? left.length() : left.length() - 1))
                                .reverse().toString();
            long palindrome = Long.parseLong(left + right);
            res.add(palindrome);
        }
        return res;
    }

    // Check if a number is palindrome in base-k
    private boolean isPalindromeInBase(long num, int k) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num % k);
            num /= k;
        }
        String s = sb.toString();
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) return false;
        }
        return true;
    }
}
