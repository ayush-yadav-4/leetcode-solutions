class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
           return 0;
        }

         if(nums.size() == 2){
           if(nums[0] > nums[1]) return 0;
           else return 1;
        }
        int st = 1,end = nums.size()-2,mid=0;
        if(nums[0] > nums[st]) return 0;
        if(nums[nums.size()-1] > nums[end]) return nums.size()-1;
        while(st<=end){
          mid = st + (end-st)/2;
          if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
             return mid;
          }
         if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]){
             st = mid+1;
          }
          else {
            end = mid-1;
          }
        }
        return mid;
    }
};