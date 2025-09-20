class Solution {
public:
    int climbStairs(int n) {
        if(n ==1) return 1;
        if(n==2) return 2;
       int cnt1 = 1, cnt2 = 2, sum = 0;
       for(int i=2;i<n;i++){
        sum = cnt1+cnt2;
        cnt1 = cnt2;
        cnt2 = sum;
       } 
       return sum;
    }
};