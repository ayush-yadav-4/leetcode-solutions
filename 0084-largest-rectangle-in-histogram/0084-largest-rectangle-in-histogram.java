class Solution {
    public int largestRectangleArea(int[] arr) {
           
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
            while(st.size() > 0 && arr[st.peek()] >= arr[i])st.pop();
            if(st.size() == 0) nge[i] = arr.length;
            else nge[i] = st.peek();
            st.add(i);
            
        }
         int ans = 0;
        for(int i=0;i<arr.length;i++){
           ans =  Math.max(ans,((nge[i] - pge[i] -1) * arr[i]));
        }
        return ans;
       

    }
}