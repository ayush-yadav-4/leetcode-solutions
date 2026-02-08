class Solution {
    class Task{
        int freq;
        int time;

        Task(int freq, int time){
          this.freq = freq;
          this.time = time;
        }
    }
    public int leastInterval(char[] tasks, int n) {
        PriorityQueue<Task> pq = new PriorityQueue<>((a,b)->{
            return b.freq - a.freq;
        });

        Queue<Task>q = new LinkedList<>();
        Map<Character, Integer> mp= new HashMap<>();
        for(int i=0;i<tasks.length;i++){
            mp.put(tasks[i], mp.getOrDefault(tasks[i], 0) + 1);
        }

        for(Map.Entry<Character,Integer> m : mp.entrySet()){
             pq.add(new Task(m.getValue(),0));
        }
        int time = 0;
        while(!pq.isEmpty() || !q.isEmpty()){
           time++;

           if(!pq.isEmpty()){
             Task t = pq.poll();
             t.freq= t.freq-1;
             if(t.freq > 0){
                t.time = time + n;
                q.add(t);
             }
           }
           if(!q.isEmpty() && q.peek().time == time){
         
             pq.add(q.poll());
          
           }
        }

        return time;
    }
}