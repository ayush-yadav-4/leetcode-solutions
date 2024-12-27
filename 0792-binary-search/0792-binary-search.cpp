class Solution {
public:
   
   int BinarySearch(vector<int>nums,int target,int start,int end){
     if(start<=end){
        
     
    int mid = start +(end -start)/2;
     if(nums[mid] == target){
       return mid;
    }
    else if(nums[mid] > target){
       return BinarySearch(nums,target,start,mid-1);
    }
     else{
     return BinarySearch(nums,target,mid+1,end);
     }
     }
     return -1;
 }

    int search(vector<int>& nums, int target) {
        int start = 0,end = nums.size()-1;
        return BinarySearch(nums,target,start,end);
    }
};