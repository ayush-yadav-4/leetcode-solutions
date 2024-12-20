class Solution {
public:
    void Swap(int a, int b,vector<int>& nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    int removeDuplicates(vector<int>& nums) {
        int idx=0,k=1;
        vector<int>ans;
        int i=0, j=1;
      
         for(int j =0; j < nums.size();j++){
           if(nums[i] != nums[j]){
            nums[i+1] = nums[j];
            i++;
            k++;
           }
         }
       
    return k;
    }
};