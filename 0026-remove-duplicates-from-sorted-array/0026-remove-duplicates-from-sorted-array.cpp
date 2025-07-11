class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //   int cnt = 0;
        //   set<int>st;
        //   vector<int>ans;

        //  for(int i=0;i<nums.size();i++){
        //     if(st.find(nums[i]) == st.end()){
        //         st.insert(nums[i]);
        //     }
           

        //  } 
        //  int i=0;
        //  for(auto it : st){
        //    nums[i] = it;
        //    i++;
        //  }
        //  return st.size();
        int i=0;
     for(int j=1;j<nums.size();j++){
          if(nums[i] != nums[j]){
             i++;
            nums[i] = nums[j];
           
          }
     }
         return i+1;
    }
};