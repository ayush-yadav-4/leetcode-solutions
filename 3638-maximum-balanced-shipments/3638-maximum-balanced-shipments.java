class Solution {
    public int maxBalancedShipments(int[] nums) {
        int i=0,cnt = 0;
        int maxi = -1000000;
        while(i<nums.length){
           if(maxi == -1000000){
            maxi = Math.max(maxi , nums[i]);
            i++;
            continue;
           }
           if(nums[i] < maxi){
            cnt++;
            i++;
            maxi = -1000000;
            continue;
           }

           maxi = Math.max(maxi,nums[i]);
           i++;
        }
        return cnt;
    }
}