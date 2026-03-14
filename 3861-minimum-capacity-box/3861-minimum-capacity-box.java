class Solution {
    public int minimumIndex(int[] capacity, int itemSize) {
         int ans = -1;
         int elem = 10000000;
        for(int i=0;i<capacity.length;i++){
           if(capacity[i] >= itemSize && capacity[i] < elem){
             ans = i;
             elem = capacity[i];
           }
        }
        
        return ans;
    }
}