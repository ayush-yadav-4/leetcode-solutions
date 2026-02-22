class Solution {
    public int[] asteroidCollision(int[] nums) {
        Stack<Integer> st = new Stack<>();
        st.add(nums[0]);
        for(int i=1;i<nums.length;i++){
           int num = nums[i];
           boolean des = false;
           while(st.size() > 0 && st.peek() > 0 && num < 0){
               if(st.peek() < -num) st.pop();
               else if(st.peek() == -num){
                st.pop();
                des = true;
                break;
               }
               else if(st.peek() > -num){
                des = true;
                break;
               }
           }
           if(des == false){
            st.add(num);
           }

          }
        

     int[] ans = new int[st.size()];
     int idx =st.size()-1;
     while(st.size() > 0){
      ans[idx--] = st.pop();
     }
     return ans;
    }
}