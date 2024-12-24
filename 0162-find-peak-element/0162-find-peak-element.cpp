class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         if(nums.size() == 1){
            return nums.size()-1;
         }
        int start=0,end=nums.size()-1,mid=0,peak =0,maxi=0;
       while(start <= end){
        mid = start + (end-start)/2;
        if(mid == start ){
            if(nums[mid] > nums[mid +1]){
                return mid;
            }else{
                return mid +1;
            }
        }
         if(mid == start ){
            if(nums[mid] > nums[mid -1]){
                return mid;
            }else{
                return mid -1;
            }
        }
       
        if(nums[mid] > nums[mid+1] && nums[mid]>nums[mid-1]){
            peak = mid;
            return mid;
        }
        else if(nums[mid] < nums[mid+1] && nums[mid]>nums[mid-1]){
            start = mid +1;
        }else{
            end = mid-1;
        }
        
       }
        return peak;
    }
};