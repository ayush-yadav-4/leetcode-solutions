class Solution {

    public long maxAlternatingSum(int[] nums) {
       

        Long[] arr = new Long[nums.length];
        for(int i=0;i<nums.length;i++){
            arr[i] =(long)( nums[i] * nums[i]);
        }
        Arrays.sort(arr);
        int i =0,j = nums.length-1;
       long ans = 0;
        while(i<=j){
            if(i == j){
                ans += arr[i];
                return ans;
            }

            ans += arr[j--];
            ans-= arr[i++];
        }
        return ans;
    }
}