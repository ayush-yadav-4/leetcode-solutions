class Solution {
    int FindArea(int[] height){
        int ans =0;
        Stack<Integer>st = new Stack<>();
      for(int i=0;i<height.length;i++){
         while(!st.empty() && height[st.peek()] >= height[i]){ 
         int curr = st.peek(); st.pop();
         int prev = (st.empty())?-1:st.peek();
          int len = i - prev -1;
         int area = len * height[curr];
         ans = Math.max(ans,area);
         }
         st.push(i);


      }

      while(!st.empty()){
       int curr = st.peek(); st.pop();
         int prev = (st.empty())?-1:st.peek();
         
         
          int len = height.length - prev -1;
         int area = len * height[curr];
         ans = Math.max(ans,area);
      }

      return ans;
    }
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int ans=0;
        int[]height = new int[matrix[0].length];
        Arrays.fill(height,0);
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                 if(matrix[i][j] == '1'){
                    height[j]++;
                 }
                 else{
                    height[j] = 0;
                 }
            }
            int area = FindArea(height);
            ans = Math.max(ans,area);
        }
        return ans;
    }
}