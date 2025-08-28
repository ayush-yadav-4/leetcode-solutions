class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer>st = new Stack<>();
      
        int ans = 0;

        for(int i=0;i<heights.length;i++){
          
          while(!st.empty() && heights[st.peek()] > heights[i]){
            int curr = heights[st.peek()]; st.pop();
            int prev = (st.empty())?-1:st.peek();
            int next = i;

            ans = Math.max(ans,(curr*(next-prev-1)));
            
            
          }
          st.push(i);
        }
         int n = heights.length;
        while (!st.isEmpty()) {
            int curr = st.pop();
            int height = heights[curr];
            int prev = (st.isEmpty()) ? -1 : st.peek();
            int width = n - prev - 1;

            ans = Math.max(ans, height * width);
        }
        return ans;
    }
}