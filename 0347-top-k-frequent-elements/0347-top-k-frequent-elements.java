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
       
        Map<Integer, Integer>mp = new HashMap<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)-> b.freq - a.freq);
        int[] ans = new int[k];
        for(int i=0;i<nums.length;i++){
           mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        for(Map.Entry<Integer, Integer> m : mp.entrySet()){
           pq.add(new Pair(m.getKey(), m.getValue()));
        }
        for(int i=0;i<k;i++){
          ans[i] = pq.poll().elem;
        }
      return ans;
    }
}