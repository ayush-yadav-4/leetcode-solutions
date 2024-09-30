class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0;int end = nums.size()-1;
        int index = nums.size();
         int mid =0;
         
        while(start <= end){
            mid = start + (end-start)/2;
            if(nums[mid] == target ){
                index = mid;
                break;
            }
            else if(nums[mid]< target){
                start = mid+1;
            }
            else if(nums[mid]> target){
                index = mid;
                end = mid-1;
            }
        }

        return index; 
    }
};