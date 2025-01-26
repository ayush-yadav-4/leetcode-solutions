class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
      
        long long ans=0; int i=0,l=0,count=0;
        int maxelem = INT_MIN;
        for(int i=0;i<nums.size();i++){
         maxelem = max(maxelem,nums[i]);
        }

        while(i<nums.size()){
           if(nums[i] == maxelem) count++;

           while(count == k){
            ans += nums.size()-i;
            if(nums[l] == maxelem) count--;
            l++;
           }
           i++;

        }
          return ans;
          
   
    }
};