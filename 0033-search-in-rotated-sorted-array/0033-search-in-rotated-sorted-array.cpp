class Solution {
public:
   int BS(vector<int>& nums, int target,int start,int end,int mid){
       
    while(start <= end){
        mid = start + (end - start)/2;
        if(nums[mid] == target){
            return mid;
        }
         if(nums[start]<= nums[mid]){
           if(nums[start]<= target && nums[mid]>= target){
            end = mid-1;
           }else{
            start = mid+1;
           }
        }
        else{
             if(nums[mid]<= target && nums[end]>= target){
            start = mid+1;
           }else{
            end = mid-1;
           }
        }
    }
    return -1;
   }
    int search(vector<int>& nums, int target) {
  
      return BS(nums,target,0,nums.size()-1,0);
    }
};