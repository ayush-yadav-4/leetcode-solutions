class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1) return;
        int st = 0,mid = 0, end = nums.size()-1;
        while(mid<=end && mid<nums.size()){
          
         if(nums[mid] == 0){
            swap(nums[mid],nums[st]);
            st++; mid++;
         }
         else if(nums[mid] == 1){
            mid++;
         }
         else if(nums[mid] == 2){
            swap(nums[mid],nums[end]);
            end--;
         }
          
        
         
         

        }
        return;
    }
};