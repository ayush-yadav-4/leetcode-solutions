class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n = nums.size(), pivot = -1,idx = 0;
        // for(int i= n-2;i>=0;i--){
        //    if(nums[i]<nums[i+1]){ pivot=i; break;}
           
        // }
        // if(pivot == -1){
        //     sort(nums.begin(),nums.end());
        //     return;
        // }
        // for(int i = n-1;i>=0;i--){
        //    if(nums[i]>nums[pivot]){ idx = i; break;}
        // }
        // swap(nums[pivot],nums[idx]);
        // reverse(nums.begin()+(pivot+1),nums.end());
        // return;

        //simpler solution .(idx after idx if found will be sorted)
        // no need to sort the array after idx
        int idx=-1,endidx=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx != -1){
         for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                endidx = i;
                break;
            }
        }
        

        swap(nums[idx],nums[endidx]);
        }
        reverse(nums.begin()+idx+1,nums.end());
    }
};