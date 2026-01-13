class Solution {
    public int mirrorDistance(int n) {
        int num1 = n,num2 = 0;
        
        while(n!=0){
           num2 = num2 * 10 + n%10;
           n = n/10;
        }

        return Math.abs(num1-num2);
    }
}