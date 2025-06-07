class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int>ans(nums.size());
//         int negative =1,positive=0;
           
//    for(int i =0 ; i < nums.size();i++){
//       if(nums[i] < 0){
//         ans[negative] = nums[i];
//         negative += 2;
//       }
//        else if(nums[i] >= 0){
//         ans[positive] = nums[i];
//         positive += 2;
//       }
//    }
//    return ans;


   vector<int>ans(nums.size());
  int neg=1,pos=0;
     for(int i =0 ; i < nums.size();i++){
        if(nums[i]>=0){
            ans[pos] = nums[i];
            pos += 2;
        }
        else{
             ans[neg] = nums[i];
            neg += 2;
        }
     }

     return ans;
    }
};