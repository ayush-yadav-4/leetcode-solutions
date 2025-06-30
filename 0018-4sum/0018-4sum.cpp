class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          sort(nums.begin(),nums.end());
        vector<vector<int>>ans; int st=0, end=0;
        long long int elem =0 ;
         if(nums.size() <4) return ans;
        set<vector<int>>set;
        for(int i=0;i<nums.size()-2;i++){
            // if(i>0 && nums[i] == nums[i-1]){
            //     continue;
            // }
            for(int j=i+1;j<nums.size()-1;j++){
            //      if(j>0 && nums[j] == nums[j-1]){
            //     continue;
            // }
            st = j+1;end = nums.size()-1;
                while(st < end){
                   elem = (nums[i] + nums[j]) ;
                   if(target>(elem+nums[st] + nums[end])){
                    st++;
                   }
                   else if(target<(elem + nums[st] + nums[end])) end--;
                   else{
                    //ans.push_back({nums[i],nums[j],nums[st],nums[end]});
                    set.insert({nums[i],nums[j],nums[st],nums[end]});
                    st++; end--;
                    while(nums[st] == nums[st-1] && st < end){
                      st++;
                    }
                   }
                }
            }
        }
       for(auto x : set){
         ans.push_back(x);
       }
        return ans;
    }
};