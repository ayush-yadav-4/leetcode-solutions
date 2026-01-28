class Solution {
    public int earliestTime(int[][] tasks) {
        int ans = 10000000;
        for(int i=0;i<tasks.length;i++){
             ans = Math.min(ans,(tasks[i][0] + tasks[i][1]));
        }

        return ans;
    }
}