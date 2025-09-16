class Solution {
    private int range = 0;   
    private int[] ranges;

    public Solution(int[] w) {
        ranges = new int[w.length];
        for (int i = 0; i < w.length; i++) {
            range += w[i];
            ranges[i] = range-1;
        }       
    }

    public int pickIndex() {
        var res = Arrays.binarySearch(ranges, (int) (Math.random() * range));
        return res >= 0 ? res : res * (-1) - 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */