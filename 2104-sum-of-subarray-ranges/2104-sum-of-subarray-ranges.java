class Solution {
    public long subArrayRanges(int[] arr) {
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
         long MOD = 1000000007; long min_sum = 0;
         for(int i=0;i<arr.length;i++){
           long left = i - pge[i];
           long right = nge[i] - i;
           min_sum += (long)((left * right) * arr[i]);
         }
         Arrays.fill(nge,0); Arrays.fill(pge, 0);
         while(st.size() > 0) st.pop();
         for(int i=0;i<arr.length;i++){
          while(st.size() > 0 && arr[st.peek()] < arr[i])st.pop();
          if(st.size() == 0) pge[i] = -1;
          else pge[i] = st.peek();
          st.add(i);
         }
         while(st.size() > 0) st.pop();

           for(int i=arr.length-1;i>=0;i--){
          while(st.size() > 0 && arr[st.peek()] <= arr[i])st.pop();
          if(st.size() == 0) nge[i] = arr.length;
          else nge[i] = st.peek();
          st.add(i);
         }

         long max_sum =0;
         for(int i=0;i<arr.length;i++){
           long left = i - pge[i];
           long right = nge[i] - i;
           max_sum += (long)(left * right * arr[i]);
         }

         return max_sum - min_sum;
    }
}