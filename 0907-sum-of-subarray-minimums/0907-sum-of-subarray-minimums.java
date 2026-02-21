class Solution {
    public int sumSubarrayMins(int[] arr) {
         int mini =10000000; int sum =0;
         int[] nge = new int[arr.length];
         int[] pge = new int[arr.length];
         Stack<Integer> st = new Stack<>();
   
        for(int i=0;i<arr.length;i++){
            while(st.size() > 0 && arr[st.peek()] > arr[i])st.pop();
            if(st.size() == 0) pge[i] = -1;
            else pge[i] = st.peek();
            st.add(i);
            
        }

        while(st.size() > 0) st.pop();
       

        for(int i=arr.length-1;i>=0;i--){
           while(st.size() > 0 &&  arr[st.peek()] >= arr[i]) st.pop();
           if(st.size() == 0) nge[i] = arr.length;
            else nge[i] = st.peek();
            st.add(i);
        }
         long ans = 0;
        long MOD = 1000000007;
        for(int i=0;i<arr.length;i++){
        
        
            int p = i - pge[i];
            int n = nge[i] - i;
           ans = (ans + (p * n % MOD) * arr[i]) % MOD;
          
        }
        return (int)ans;
    }
}