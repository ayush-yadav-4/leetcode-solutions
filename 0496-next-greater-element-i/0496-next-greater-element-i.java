class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer>mp = new HashMap<>();
        Stack<Integer>st = new Stack<>();
        int[] ans = new int[nums1.length];
        mp.put(nums2[nums2.length-1] ,-1);
        st.push(nums2[nums2.length-1]);
        for(int i=nums2.length-2;i>=0;i--){

           while(!st.empty() && st.peek() <= nums2[i] ){
             st.pop();
           }
           if(st.empty()) mp.put(nums2[i],-1);
           else  mp.put(nums2[i],st.peek());;
           st.push(nums2[i]);
        }

        for(int i=0;i<nums1.length;i++){
            ans[i] = mp.get(nums1[i]);
        }
        return ans;

    }
}