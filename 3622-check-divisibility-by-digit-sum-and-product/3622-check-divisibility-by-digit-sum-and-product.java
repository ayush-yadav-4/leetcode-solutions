class Solution {
    public boolean checkDivisibility(int n) {
        int digitsum = 0, digitprod = 1;
        int num = n;
        while(num != 0){
          digitsum += num%10;
          digitprod *= num%10;
          num = num/10;
        }

        return n % (digitsum + digitprod) == 0;
    }
}