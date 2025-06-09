class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
    //     stable_sort(nums.begin(),nums.end());
    // int count =0,curr =INT_MIN,maxi =0;
    //     for(int i=0;i < nums.size();i++){
    //         if(nums[i]-1 == curr){
    //             curr = nums[i];
    //             count++;
    //         }
    //         else if(nums[i] == curr){
    //             continue;
    //         } 
    //         else{
    //             curr = nums[i];
    //             count =1;
    //         }
    //         maxi = max(count,maxi);

    //     }
    //     return maxi;

        //with set
         unordered_set<int>mp;
        for(int i=0;i<nums.size();i++){
           mp.insert(nums[i]);
        }
        int cnt=0,ans=0;
        for(int elem : mp){
            if(mp.find(elem-1) == mp.end()){
            int num = elem;
            cnt=0;
          while(mp.find(num) != mp.end()){
            num++;
            cnt++;
          }
            }
          ans = max(ans,cnt);
        
        }
        return ans;
    }
};