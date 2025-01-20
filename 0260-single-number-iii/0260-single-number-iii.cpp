class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int b1=0,b2=0,rightmost=0; long xor1=0;
        for(int i=0;i<nums.size();i++){
            xor1 = xor1^nums[i];
        }
       rightmost = xor1 & (-xor1);
         b1=0; b2=0;
        for(int i=0;i<nums.size();i++){
         if((nums[i]&rightmost)){
            b1 = b1^nums[i];
         }else{
            b2 = b2^nums[i];
         }

        }
        return {b1,b2};
    }
};