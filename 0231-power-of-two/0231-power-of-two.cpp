class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
         long ans = n;
         return (ans&(ans-1)) == 0;
       
    }
};