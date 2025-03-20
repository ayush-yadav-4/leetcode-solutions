class Solution {
public:
    int countDigits(int num) {
        
       int n = num,ans = 0;
       while(n != 0){
        int no = n%10;
         if(num%no == 0) ans++;
         n = n/10;
       }
       return ans;
    }
};