class Solution {
    class Pair{
        int val; int freq;
        Pair(int val, int freq){
            this.val = val;
            this.freq= freq;
        }

    }
    public boolean isNStraightHand(int[] hand, int n) {
        if(hand.length < n) return false;
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)->{
            if(a.val < b.val) return a.val-b.val;
            return a.val-b.val;
        });
        Map<Integer, Integer> mp = new HashMap<>();
        Queue<Pair> q = new LinkedList<>();

        for(int i=0;i<hand.length;i++){
           mp.put(hand[i], mp.getOrDefault(hand[i],0)+1);
        }

        for(Map.Entry<Integer, Integer>m : mp.entrySet()){
             pq.add(new Pair(m.getKey(), m.getValue()));
        }
      
  int cnt = 0;
        while(pq.size() > 0){
            Pair p = null;
            int k = n;
            while(k>0){
                if(p == null){
                   p = pq.poll();
                   p.freq--;
                   if(p.freq>0){
                    q.add(p);
                   }
                }
                else{
                    if(pq.size() == 0) return false;
                    if((p.val+1) == pq.peek().val){
                        p = pq.poll();
                          p.freq--;
                   if(p.freq>0){
                    q.add(p);
                   }
                }
                    
                    else{
                        return false;
                    }
                }
                k--;
               

            }
            while(q.size()>0){
                pq.add(q.poll());
            }
            cnt++;
        }
        return true;
    }
}