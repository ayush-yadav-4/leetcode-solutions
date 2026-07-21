class Solution {


    public boolean canReach(int[] start, int[] target) {
        int dirs[][] = { 
            {2,1},{2,-1},{-2,1},{-2,-1},
        {1,2},{1,-2},{-1,2},{-1,-2}
        };

        Queue<int[]>q = new LinkedList<>();
        boolean vis[][] = new boolean[8][8];
        for(boolean a[] : vis){
            Arrays.fill(a,false);
        }
        q.add(new int[]{start[0], start[1],0});


        vis[start[0]][start[1]] = true;
        while(!q.isEmpty()){
          int i = q.peek()[0];
          int j = q.peek()[1];
          int cnt = q.peek()[2];
          q.remove();
          if(i == target[0] && j == target[1]){
            return cnt%2==0;
          }
          for(int[] d : dirs){
            int ix = i + d[0];
            int jx = j + d[1];

            if(ix >= 0 && ix<=7 && jx >= 0 && jx <= 7 && vis[ix][jx]== false ){
                q.add(new int[]{ix,jx,cnt+1});
                vis[ix][jx] = true;
                
            }
          }
          
        }
        return false;

    }
}