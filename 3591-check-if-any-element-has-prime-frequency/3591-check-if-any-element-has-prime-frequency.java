class Solution {
    boolean isPrime(int n){
        if(n==1) return false;
         for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0) return false;
         }
         return true;
    }
    public boolean checkPrimeFrequency(int[] nums) {
        
        Map<Integer,Integer>mp = new HashMap<>();

        for(int i=0;i<nums.length;i++){
           mp.put(nums[i], mp.getOrDefault(nums[i],0)+1); 
        }

        for(Map.Entry<Integer,Integer>m : mp.entrySet()){
           if(isPrime(m.getValue())){
             return true;
           }
        }
        return false;
    }
}