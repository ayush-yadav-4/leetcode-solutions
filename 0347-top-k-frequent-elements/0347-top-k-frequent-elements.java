class Solution {

    class Pair{
        int elem;
        int freq;

        Pair(int elem, int freq){
          this.elem = elem;
          this.freq = freq;
        }
    }
    public int[] topKFrequent(int[] nums, int k) {
       
        Map<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)->{
            return b.freq-a.freq;
        });
        for(int i=0;i<nums.length;i++){
           mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }
  
        for(Map.Entry<Integer, Integer> m : mp.entrySet()){
            pq.add(new Pair(m.getKey(), m.getValue()));
        }
      int[] arr = new int[k];
      for(int i=0;i<k;i++){
       arr[i] = pq.peek().elem;
       pq.poll();
      }
      
      return arr;
    }
}