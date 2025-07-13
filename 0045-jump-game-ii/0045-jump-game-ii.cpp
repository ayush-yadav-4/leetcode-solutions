class Solution {
public:

    int jump(vector<int>& nums) {

        int jump = 0,l=0,r=0;
     while(r<nums.size()-1){
       int size = 0;
       for(int i=l;i<=r;i++){
          size = max(size,i+nums[i]);
       }
       l =r+1;
       r = size;
       jump++;
     }
     return jump;
    }
};