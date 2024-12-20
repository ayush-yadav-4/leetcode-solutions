class Solution {
public:


void Swap(int a , int b , vector<int>& nums){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
    void moveZeroes(vector<int>& nums) {
        int j =0;

        for(int i =0; i< nums.size();i++){
          if(nums[i] == 0){
            j =i;
            break;
          }
          if(i == nums.size()-1){
            return;
          }
        }

        for(int i =j+1; i< nums.size();i++){
           if(nums[i]!=0){
            Swap(j,i,nums);
            j++; 
           }
          
      
    }
    }
};