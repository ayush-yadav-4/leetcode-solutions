class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        int st = 0, end = nums.length - 1;
        int ans1 =-1, ans2 = -1;
        while(st<=end){
            int mid  = (st + end)/2;

            if(nums[mid] == target){
            ans1 = mid;
            end = mid-1;
            }
            else if(nums[mid] > target) end = mid-1;
            else st = mid+1;
        }
        st = 0; end = nums.length - 1;
         while(st<=end){
            int mid  = (st + end)/2;

            if(nums[mid] == target){
            ans2 = mid;
            st = mid+1;
            }
            else if(nums[mid] < target)st = mid+1;
            else end = mid-1;
        }

        return new int[]{ans1,ans2};

        
    }
}