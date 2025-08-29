class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        
        // Step 1: find max k (number of complete gifts we can give)
        long left = 0, right = candies;
        long k = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            long sum = mid * (mid + 1) / 2;
            if (sum <= candies) {
                k = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Step 2: distribute first k gifts
        // total sum of first k numbers = k*(k+1)/2
        long totalUsed = k * (k + 1) / 2;
        int remaining = (int)(candies - totalUsed);
        
        // Each person i gets their arithmetic sequence share
        for (int i = 0; i < num_people; i++) {
            // gifts given to person i are: i+1, i+1+num_people, i+1+2*num_people, ...
            long count = (k - i + num_people - 1) / num_people; // how many gifts this person got
            if (count > 0) {
                // sum of arithmetic sequence
                ans[i] = (int)(count * (2L * (i + 1) + (count - 1) * num_people) / 2);
            }
        }
        
        // Step 3: distribute the remaining candies
        if (remaining > 0) {
            ans[(int)(k % num_people)] += remaining;
        }
        
        return ans;
    }
}
