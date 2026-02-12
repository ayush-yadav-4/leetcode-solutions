class Solution {
    void DFS(int i , int j , int[][]image,int color , int src){
        image[i][j] = color;
        int[] rows = {0,0,-1,+1};
        int[] cols = {-1,+1,0,0};

        for(int idx=0;idx<=3;idx++){
          int r = i + rows[idx];
          int c = j + cols[idx];

          if(r >=0 && r <image.length && c >=0 && c < image[0].length && image[r][c] == src){
            
            DFS(r,c,image,color,src);
          } 
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(sr<0 || sr >= image.length || sc < 0 || sc>=image[0].length) return image;
        int src = image[sr][sc];
        if(src == color) return image;
        DFS(sr,sc,image,color,src);

        return image;
    }
}