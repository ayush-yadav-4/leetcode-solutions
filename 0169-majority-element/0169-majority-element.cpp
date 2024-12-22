class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;int elem =0;
         
        for(int i =0; i < nums.size() ; i++){
              if(count == 0){
            elem = nums[i]; 
            count =1;
          }
        else if(nums[i] == elem){
             count++;
          }
          else{
            count--;
          }
        
        }
        return elem;
    
    }
};