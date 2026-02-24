class Solution {

    int factorial(int num){
        int sum =1;
       for(int i=num;i>=1;i--){
         sum = sum * i;
       }

       return sum;
    }
    public boolean isDigitorialPermutation(int n) {

        Map<Integer, Integer>mp = new HashMap<>();
         int num1 =n;
         int num = n;
         while(n > 0){
           int digit = n %10;
           mp.put(digit, mp.getOrDefault(digit,0) + 1);
           n = n/10;
         }
         int sum =0;
         while(num > 0){
            int digit = num%10;
           sum += factorial(digit);
           num = num/10;
         }
        if(sum == num1) return true;
         while(sum > 0){
            int digit = sum %10;
            if(mp.containsKey(digit) == false) return false;
            else {
                mp.put(digit, mp.get(digit)-1);
                if(mp.get(digit) == 0){
                    mp.remove(digit);
                }
            }

            sum = sum/10;
         }

     
         if(mp.size() == 0) return true;
         return false;
    }
}