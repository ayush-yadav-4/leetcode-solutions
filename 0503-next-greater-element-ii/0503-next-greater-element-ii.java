class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int[] nums1 = new int[(nums.length)];
        Arrays.fill(nums1, -1);
        for(int i = 0 ; i < (2*nums.length); i++ ){
            while(!st.isEmpty() && nums[i%nums.length] > nums[st.peek()]){
                nums1[st.peek()] = nums[i%nums.length];
                st.pop();
            }
            st.push(i%nums.length);
        }

        return nums1;
    }
}