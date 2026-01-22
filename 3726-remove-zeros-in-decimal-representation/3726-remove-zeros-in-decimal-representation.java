class Solution {
    public long removeZeros(long n) {
        StringBuilder str = new StringBuilder(Long.toString(n));
         long ans = 0;
        for(int i=0;i<str.length();i++){
           if(str.charAt(i)-'0' > 0){
               ans = ans * 10 + (str.charAt(i)-'0');
           }
        }

        return ans;
    }
}