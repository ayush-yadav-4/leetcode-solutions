class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pivot = -1,idx = 0;
        for(int i= n-2;i>=0;i--){
           if(nums[i]<nums[i+1]){ pivot=i; break;}
           
        }
        if(pivot == -1){
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i = n-1;i>=0;i--){
           if(nums[i]>nums[pivot]){ idx = i; break;}
        }
        swap(nums[pivot],nums[idx]);
        reverse(nums.begin()+(pivot+1),nums.end());
        return;
    }
};