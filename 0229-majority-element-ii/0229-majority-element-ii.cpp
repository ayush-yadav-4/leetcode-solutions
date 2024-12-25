class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count1 =0,count2 =0,elem1 =0,elem2 =0,n = floor(nums.size()/3);
        for(int i = 0; i < nums.size();i++){
            if(count1 ==0 && elem2 != nums[i] ){
                count1 =1;
                elem1 = nums[i];
            }else if(count2 ==0 && elem1 != nums[i] ){
                count2 =1;
                elem2 = nums[i];
            }
            else if(elem1 == nums[i]){
                count1++;
            }
             else if(elem2 == nums[i]){
                count2++;}
                else {
                count1--; count2--;
            }
           
            
               
             }
              count1 =0; count2=0;
              for(int i = 0; i < nums.size();i++){
               if(nums[i] == elem1){count1++;}
                if(nums[i] == elem2){count2++;}
              }
                if(count1 >n){
                   ans.push_back(elem1);
                }
                if(count2 >n && elem1 !=elem2){
                   ans.push_back(elem2);
                }
      
      
   
        return ans;
        }
    
    
};