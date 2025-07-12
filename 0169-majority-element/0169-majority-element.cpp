class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = 0,cnt =0;
        for(int i = 0;i<nums.size();i++){
            if(cnt == 0){
                elem = nums[i];
                cnt++;
            }
           else if(elem == nums[i]){
                cnt++;
            }
            else cnt--;
        }
        return elem;
    }
};