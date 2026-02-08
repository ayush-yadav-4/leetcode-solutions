class Solution {
    int[] findmaxi(int st, int end, int[] nums){
      int mini = Integer.MAX_VALUE, maxi = 0;
     for(int i=st;i<=end;i++){
       maxi = Math.max(maxi, nums[i]);
       mini = Math.min(mini, nums[i]);
     }
     return new int[]{maxi,mini};
    }
   
    public long countSubarrays(int[] nums, long k) {
        Deque<Integer>mindq = new ArrayDeque<>();
         Deque<Integer>maxdq = new ArrayDeque<>();
        long cnt = 0;double cost =0;
        int r = 0, l =0;
        long mini = Long.MAX_VALUE, maxi =0;
        while(r<nums.length){

            while(!mindq.isEmpty() && nums[mindq.peekLast()] >= nums[r]){
                mindq.pollLast();
            }
            mindq.addLast(r);
             while(!maxdq.isEmpty() && nums[maxdq.peekLast()] <= nums[r]){
                maxdq.pollLast();
            }
            maxdq.addLast(r);
            while(!mindq.isEmpty() && !maxdq.isEmpty() ){
               maxi =nums[maxdq.peekFirst()];
           mini = nums[mindq.peekFirst()];
           cost = (maxi - mini) * (r-l+1);
           

           if(cost <= k) break;

           if(mindq.peekFirst() == l)mindq.pollFirst();
           if(maxdq.peekFirst() == l)maxdq.pollFirst();
           l++;

            }
           

        //    while(cost > k){
        //      l++;
        //      int[] arr = findmaxi(l,r,nums);
        //      maxi = arr[0];
        //      mini = arr[1];
        //      cost = (maxi - mini) * (r-l+1);
            
        //    }
        //    if(cost <= k)cnt+=(r-l+1);
        cnt += (r-l+1);
           r++;

        }
        return cnt;
    }
}