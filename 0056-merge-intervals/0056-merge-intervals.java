class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        for(int i=0;i<intervals.length;i++){
             int st = intervals[i][0];
             int end = intervals[i][1];
            if(ans.size() > 0 && st <= ans.get(ans.size()-1)[1]) continue;
             for(int j =i+1;j<intervals.length;j++){
              if( end >= intervals[j][0]){
                end = Math.max(end, intervals[j][1]);
              }
              else break;
             }

             ans.add(new int[]{st, end});
        }

        int[][] mat = new int[ans.size()][2];
        for(int i=0;i<ans.size();i++){
          mat[i][0] = ans.get(i)[0];
          mat[i][1] = ans.get(i)[1];
        }
        return mat;
    }
}