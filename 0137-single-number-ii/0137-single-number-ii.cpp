class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0,cnt = 0;
        
        
        for(int bitset = 0; bitset<=31;bitset++){
            cnt=0;
            for(int i = 0 ; i< nums.size();i++){
               if( (nums[i]&(1<<bitset))){
                cnt++;
               }
            }
            if (cnt%3 == 1){
                ans = (ans | (1<<bitset));
            }
        }
        return ans;
        
    }
};