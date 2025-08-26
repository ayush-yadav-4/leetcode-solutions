class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer>st = new Stack<>();
        int[]ans = new int[nums.length];
        st.push(nums[nums.length-1]);
        for(int i = 2*(nums.length)-1;i>=0;i--){
          
          while(!st.empty() && st.peek() <= nums[i%nums.length]){
            st.pop();
          }
          if(i<= nums.length-1){
               if(st.empty()) ans[i] = -1;
               else ans[i] = st.peek();
          }
          st.push(nums[i%nums.length]);
        }
        return ans;
    }
}