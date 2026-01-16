class Solution {
    void swap(StringBuilder str, int idx1,int idx2){
      char temp = str.charAt(idx1);
      str.setCharAt(idx1,str.charAt(idx2));
      str.setCharAt(idx2,temp);
    }
    public long maximumScore(int[] nums, String str) {

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a,b)->{
                if(a[0] != b[0]) return b[0] - a[0];
                return b[1] - a[1];
            }
        );
        StringBuilder s = new StringBuilder(str);
        long ans = 0;
        for(int i =0;i<nums.length;i++){
            if(s.charAt(i) == '0'){
                pq.add(new int[]{nums[i],i});
            }
            else if(s.charAt(i) == '1'){
                if(pq.size() >= 1 && pq.peek()[0] > nums[i]){
                    swap(s,i,pq.peek()[1]);
                    ans += pq.peek()[0];
                    pq.poll();
                    pq.add(new int[]{nums[i],i});
                }
                else{
                    ans += nums[i];
                }
            }
        }
        return ans;
    }
}