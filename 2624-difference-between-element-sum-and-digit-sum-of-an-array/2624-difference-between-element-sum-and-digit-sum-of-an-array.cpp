class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int num=0,sum=0;
        for(int n:nums){
     sum += n;
     if(n>9){
     while(n!=0){
        num += n%10;
        n = n/10;
     }
     }
     else num += n;
        }
        return sum-num;
    }
};