class Solution {

    class Node{
        int first;
        int second;

        Node(int first , int second){
          this.first = first;
          this.second = second;
        }
    }
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        List<int[]>ls = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        for(int i=0;i<profits.length;i++){
           ls.add(new int[]{capital[i],profits[i]});
        }
        Collections.sort(ls,(a,b)->{
            if(a[0]<b[0]) return a[0] - b[0];
            else if(a[0] == b[0]){
                 if(a[1]<b[1]) return a[1] - b[1];
                 else return b[1] - a[1];
             }
             return a[0] - b[0];

        });
        int ans = w,idx = 0,i=0;

      while(k>0){
          
          while(idx<profits.length){
               if(ls.get(idx)[0] > w)break;
               pq.add(ls.get(idx)[1]);
               idx++;
               
          }
          if(pq.size() <= 0) return ans;
          ans += pq.peek();
          w+= pq.peek();
          pq.poll();
          k--;
      }
        return ans;
    }
}