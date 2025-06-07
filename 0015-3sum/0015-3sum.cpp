class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//    int sum =0,start =0,end=0;
//         vector<vector<int>>ans;
//         sort(nums.begin(),nums.end()); //logn
        
//         for(int i=0; i < nums.size();i++){ //approx n
//            if(i>0 && nums[i] == nums[i-1]){
//             continue;
//            }
//             start = i+1; end = nums.size()-1;
//             while(start < end){ // approx n
//                 sum = nums[i]+nums[start]+nums[end];
//                if(sum < 0){
//                 start++;
//                } else if(sum > 0){
//                  end--;
//                }
//                else{
        
//                 ans.push_back({nums[i],nums[start],nums[end]});
//                 start++; end--;
//                    while((nums[start] == nums[start-1]) && start<end){
//                     start++;    
//                 }
//                }
            

//                     }
//         }
                  
//              return ans;



      set<vector<int>>st;
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size()-1;i++){
          int l = i+1,r = nums.size()-1;
          int sum = 0;
          while(l<r){
            sum = (nums[l] + nums[r] + nums[i]);
            if(sum == 0){st.insert({nums[i],nums[l],nums[r]}); l++;r--; }
            else if (sum > 0) r--;
            else l++;
          }
       }
       for(auto it : st){
          ans.push_back(it);
       }
       return ans;
    }
    
};