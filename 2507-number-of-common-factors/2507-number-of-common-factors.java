class Solution {
    public int commonFactors(int a, int b) {
        int gcd = findGCD(a, b);
        int count = 0;
        
        for (int i = 1; i * i <= gcd; i++) {
            if (gcd % i == 0) {
                count++; // i is a factor
                if (i != gcd / i) count++; // gcd/i is another distinct factor
            }
        }
        
        return count;
    }
    
    private int findGCD(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
}