class KthLargest {

    PriorityQueue<Integer> pq = new PriorityQueue<>();
    int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;

        for(int num : nums){
            add(num);   // reuse logic
        }
    }
    
    public int add(int val) {

        if(pq.size() < k){
            pq.add(val);
        }
        else if(pq.peek() < val){
            pq.poll();
            pq.add(val);
        }

        return pq.peek();
    }
}
