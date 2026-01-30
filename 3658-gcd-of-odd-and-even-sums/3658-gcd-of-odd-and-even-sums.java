class Solution {
    int helper(int a , int b){
       int num = Math.min(a,b);
       int ans = 0;
       for(int i=1;i<=num;i++){
          if(a%i == 0 && b%i == 0){
            ans = i;
          }
       }

       return ans;

    }
    public int gcdOfOddEvenSums(int n) {
         int odd = 0, eve = 0;
         int oddnum = 1, evennum = 2;
         
         while(n>=1){
            odd += oddnum;
            eve += evennum;
            oddnum += 2;
            evennum += 2;
            n--;
         }

         int ans = helper(odd,eve);
         return ans;
    }
}