class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int maxi =0;
       for(int a: nums){
         maxi = Math.max(a,maxi);
       }
        int[] freq = new int[maxi+1]; // since nums[i] <= 10
        int duplicates = 0;

        // initial frequency count
        for (int x : nums) {
            freq[x]++;
            if (freq[x] == 2) duplicates++;
        }

        // already distinct
        if (duplicates == 0) return 0;

        int ops = 0;
        int idx = 0;

        while (idx < n) {
            ops++;

            // remove first 3 elements (or remaining)
            for (int i = 0; i < 3 && idx < n; i++, idx++) {
                int val = nums[idx];
                if (freq[val] == 2) duplicates--; // going from duplicate → unique
                freq[val]--;
            }

            if (duplicates == 0) return ops;
        }

        return ops;
    }
}
