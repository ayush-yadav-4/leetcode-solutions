class Solution {
    public int scheduleCourse(int[][] courses) {
        int time =0; int deadline = 0; int cnt =0;
        Arrays.sort(courses,(a,b)->{
            return a[1] - b[1];
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder()); 

        for(int i=0;i<courses.length;i++){
           int dead = courses[i][1];
           if(courses[i][0]<=courses[i][1]){
             if(time + courses[i][0] <= courses[i][1]){
                pq.add(courses[i][0]);
                time += courses[i][0];
             }
             else if(pq.peek() > courses[i][0]){ 
              time -= pq.poll();
              pq.add(courses[i][0]);
              time += courses[i][0];
              
             }
           }
        }
        return pq.size();
    }
}