class Solution {
    public int alternateDigitSum(int n) {
        int sum = 0,cons = 1,ne= 0;
        while(n>0){
            ne = ne *10 + n%10;
            n /= 10;
        }
        while(ne>0){
            sum = sum + (ne%10 * cons);
            ne /= 10;
            cons *= -1;
        }
        return sum;
    }

}