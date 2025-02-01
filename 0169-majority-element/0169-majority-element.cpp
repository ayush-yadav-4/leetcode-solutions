class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;int elem =0;
         for(int i=0;i<nums.size();i++){
            if(nums[i] == elem){
                ans++;
            }
            else if(ans ==0){
                elem = nums[i]; ans++;
            }
            else{
                ans--;
            }
         }
        return elem;
    
    }
};