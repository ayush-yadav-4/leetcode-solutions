class Solution {
    public boolean isPalindrome(int x) {
        if(x< 0) return false;
        int y = reverse(x);
        if(x == y) return true;
        return false;
    }

    int reverse(int a){
        int sum=0;int n=a;
        while(n!=0){
            sum = (sum*10) + (n%10);
            n /=10;
        }
        return sum;
    }
}