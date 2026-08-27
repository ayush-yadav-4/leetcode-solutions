class Solution {
    public int kthSmallest(int[][] mat, int k) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int i=0;i<mat.length;i++){
            for(int j = 0;j<mat[0].length;j++){
              if(pq.size() < k){
               pq.add(mat[i][j]);
              }
              else if(pq.size() == k && pq.peek() > mat[i][j]){
               pq.poll();
               pq.add(mat[i][j]);
              }
            }
        }

         return pq.peek();
    }
}