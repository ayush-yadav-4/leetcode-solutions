class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        
       Arrays.sort(intervals,(a,b)->Integer.compare(a[1],b[1]));
       int end = intervals[0][1],cnt=0;
        for(int i=1;i<intervals.length;i++){
              if(intervals[i][0] < end){
                cnt++;
                continue;
              }
               end = intervals[i][1];
        }
        return cnt;
    }
}