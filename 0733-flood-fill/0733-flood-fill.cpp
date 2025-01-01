class Solution {
public:

void colour(vector<vector<int>>& image, int r, int c, int color,int elem){
   if(r<0 || c<0 || r== image.size() || c== image[0].size() || image[r][c] != elem){
     return;
   }
   if(image[r][c] == elem){
    image[r][c] = color;
   }

 
  colour(image,r+1,c,color,elem);
  colour(image,r-1,c,color,elem);
  colour(image,r,c+1,color,elem);
  colour(image,r,c-1,color,elem);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int elem = image[sr][sc];
        if(elem == color){
            return image;
        }
        colour(image,sr,sc,color,elem);
        return image;
    }
};