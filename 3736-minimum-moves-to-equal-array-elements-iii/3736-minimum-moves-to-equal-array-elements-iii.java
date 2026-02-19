class Solution {
    public int minMoves(int[] nums) {
        int maxi = 0, sum = 0;

        for(int num : nums){
          maxi = Math.max(maxi, num);
          sum += num;
        }

        int total = maxi * nums.length;
        return total - sum;
    }
}