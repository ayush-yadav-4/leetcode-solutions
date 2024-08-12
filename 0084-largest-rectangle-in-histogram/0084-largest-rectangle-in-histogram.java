class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights.length == 1){
            return heights[0];
        }
           
       int count = 0;
       int[] ans = new int[(heights.length)];
       int[] rightans = new int[(heights.length)];
       int[] leftans = new int[(heights.length)];
       Arrays.fill(rightans,1);
       Arrays.fill(leftans,-1);
        Stack<Integer> st = new Stack<>(); 
        
          for(int i = 0; i < heights.length; i++){
        while(!st.isEmpty() && heights[i]< heights[st.peek()]){
            rightans[st.peek()] = i;
            st.pop();
        }
        st.push(i);
          }

          while(!st.isEmpty()){
            rightans[st.peek()] = heights.length;
            st.pop();
          }
               for(int i = heights.length -1; i >=0; i--){
        while(!st.isEmpty() && heights[i]< heights[st.peek()]){
            leftans[st.peek()] = i;
            st.pop();
        }
        st.push(i);
          }

        
        for(int i = 0; i < heights.length; i++){
           ans[i] = heights[i] * (rightans[i] - leftans[i] - 1);
        }
          int max = 0;
         for(int i = 0; i < ans.length; i++){
            if(ans[i]> max) max = ans[i];
        }
        return max;
        
    }
     
}