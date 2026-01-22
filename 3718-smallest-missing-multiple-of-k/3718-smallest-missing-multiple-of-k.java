class Solution {
    public int missingMultiple(int[] nums, int k) {
        
        Set<Integer>st = new HashSet<>();

        for(int a : nums){
           st.add(a);
        }
        int i =1,num=k;
        while(i<=200){
             int n =( k * i);
           if(st.contains(n) == false) return n;
           i++;
        }
        return -1;
    }
}