import java.util.*;

class Solution {
    public long minimalKSum(int[] nums, int k) {
        Arrays.sort(nums);
        Set<Integer> set = new HashSet<>();
        List<Integer> list = new ArrayList<>();
        
        // Remove duplicates
        for (int num : nums) {
            if (set.add(num)) {
                list.add(num);
            }
        }

        long sum = 0;
        int prev = 0;

        for (int num : list) {
            int gap = num - prev - 1;  // number of missing integers between prev and num
            if (gap > 0) {
                int take = Math.min(gap, k);
                long l = prev + 1;
                long r = prev + take;
                sum += (r * (r + 1) / 2) - ((l - 1) * l / 2);
                k -= take;
                if (k == 0) return sum;
            }
            prev = num;
        }

        // Still need to take remaining k numbers after last element
        long l = prev + 1;
        long r = prev + k;
        sum += (r * (r + 1) / 2) - ((l - 1) * l / 2);
        return sum;
    }
}
