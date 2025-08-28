class Solution {
    private static final int MOD = 1_000_000_007;

    public int numberOfWays(String corridor) {
        int n = corridor.length();
        List<Integer> seats = new ArrayList<>();

        // Step 1: Collect indices of all seats
        for (int i = 0; i < n; i++) {
            if (corridor.charAt(i) == 'S') {
                seats.add(i);
            }
        }

        int totalSeats = seats.size();
        // Step 2: Handle edge cases
        if (totalSeats == 0 || totalSeats % 2 == 1) return 0;
        if (totalSeats == 2) return 1;

        long ways = 1;
        // Step 3: Multiply number of ways for each gap between seat pairs
        for (int i = 2; i < totalSeats; i += 2) {
            int prevSeat = seats.get(i - 1);
            int nextSeat = seats.get(i);
            // plants (or positions) between seat pairs
            int gap = nextSeat - prevSeat;
            ways = (ways * gap) % MOD;
        }

        return (int) ways;
    }
}
