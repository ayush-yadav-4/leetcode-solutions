class Solution {
    public long sumAndMultiply(int n) {
        StringBuilder str = new StringBuilder(Integer.toString(n));
       
        long ans = 0, sum = 0;
        for(int i=0;i<str.length();i++){
            int digit = str.charAt(i) - '0';
            if(digit > 0){
                ans = ans * 10 + digit;
                sum += digit;
            }
            
            
        }

        return ans * sum;
    }
}