class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =0,k=0;
        for(int i =0; i< nums.size();i++){
           if(nums[i]!=0){
            nums[j] = nums[i];
            j++; 
           }
           if(nums[i] == 0){
            k++;
           }
        }
         for(int i =0; i< k;i++){
            nums.pop_back();
         }
         for(int i =0; i< k;i++){
            nums.push_back(0);
         }

    }
};