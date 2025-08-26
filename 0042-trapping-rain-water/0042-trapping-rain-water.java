class Solution {
    public int trap(int[] heights) {
        
        int l =0,r = heights.length-1,ans=0;
        int maxleft = 0,maxright = 0;
        while(l<=r){
            if(heights[l]<=heights[r]){
                if(maxleft>heights[l]){
                   ans+= maxleft - heights[l];
                   
                
                }
                maxleft = Math.max(maxleft,heights[l]);
                l++;
            }
                else {
                    if(maxright>heights[r]){
                        ans += maxright - heights[r];
                       
                        
                    }
                     maxright = Math.max(maxright,heights[r]);
                    r--;
                }
            
        }

        return ans;
    }
}