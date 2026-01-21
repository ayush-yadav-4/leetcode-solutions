class Solution {
    public int minimumDistance(int[] nums) {
Map<Integer, List<Integer>> mp = new HashMap<>();
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            mp.putIfAbsent(nums[i], new ArrayList<>());
            List<Integer> ls = mp.get(nums[i]);

            if (ls.size() >= 2) {
                int fir = ls.get(ls.size() - 2);
                int sec = ls.get(ls.size()-1);
                ans = Math.min(ans, Math.abs(fir-sec) + Math.abs(fir-i) + Math.abs(sec-i));
            }

            ls.add(i);
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
        
}