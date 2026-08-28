class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer>dq = new ArrayDeque<>();
         ArrayList<Integer> ls = new ArrayList<>();
         for(int i=0;i<nums.length;i++){
           
           if(!dq.isEmpty() && dq.peekFirst() <= i-k){
            dq.pollFirst();
           }
           while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]){
            dq.pollLast();
           }
            dq.addLast(i);
           if(i>=k-1){
             ls.add(nums[dq.peekFirst()]);
           }
         }
         
         int[] ans = new int[ls.size()];
         int idx =0;
        for(int i=0;i<ls.size();i++){
           ans[idx++]= ls.get(i);
        }

        return ans;
    }
}