class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int count =1,ans = 0,flag=0;
         for(int i =0; i < nums.size(); i++){
            flag =0;
        for(int j =0; j < nums.size(); j++){
           if( nums[i] == nums[j] ){
               flag++;
           }
           if(j == nums.size()-1 && flag == 1){
             ans = nums[i];
             return ans;
           }
         }
         }
        return ans;
    }
};