class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,l=0,r=0,ans=0,len=0,size=0;
        while(r<nums.size()){
            if(nums[r] == 0){
                size++;
            }
            while(size>k){
             
              if(nums[l] == 0)
              size--;
              l++;
            }
            if(size<=k){
            len = r-l+1;
            ans = max(ans,len);
            }
            
          
            r++;
        }
        return ans;
    }
};