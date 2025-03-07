class Solution {
public:
    int differenceOfSums(int n, int m) {
        // Sum of all integers from 1 to n
        int totalSum = n * (n + 1) / 2;
        
        // Number of integers divisible by m in the range [1, n]
        int k = n / m;
        
        // Sum of all integers divisible by m
        int divisibleSum = m * k * (k + 1) / 2;
        
        // num1 is totalSum minus divisibleSum
        int num1 = totalSum - divisibleSum;
        
        // num2 is divisibleSum
        int num2 = divisibleSum;
        
        // Return the difference
        return num1 - num2;
    }
};
