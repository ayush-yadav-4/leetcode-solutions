class Solution {
    boolean isPrime(int n){
        int cnt =0;
        for(int i =2;i<=Math.sqrt(n);i++){
          if(n%i == 0)cnt++;
        }
        if(cnt>=1) return false;
        return true;
    }
    public int largestPrime(int n) {
        int ans =0,i=2,num=0;

        while(num < n){
            if(isPrime(i)){
                if(num+i > n)return ans;
                num += i;
                if(isPrime(num))ans = num;
               
            }
            i++;
        }
        return ans;
    }
}