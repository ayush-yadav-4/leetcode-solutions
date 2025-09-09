class Solution {
    public long power(long b, long p, long m){
        if(p == 0) return 1;
        long t = power(b, p/2, m);
        return (p%2 == 1)? ((((t*t)%m) * b)%m): (t * t)%m;
    }
    
    public int numberOfGoodPartitions(int[] nums) {
        long count = 0, m = 1000_000_007;
        HashMap<Integer, Integer> last = new HashMap<>();
        for(int i = 0; i < nums.length; ++i) last.put(nums[i], i);
        for(int i = 0, next = -1; i < nums.length; ++i) {
            if(i > next) ++count;
            next = Math.max(next, last.get(nums[i]));
        }
        return (int)power(2, count - 1, m);
    }
}