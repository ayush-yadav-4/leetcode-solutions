class Solution {
     static int comp(int[] a, int[] b){
       if(a[0] < b[0]) return 1;
       return 0;
    }
    public int[][] merge(int[][] intervals) {
         Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int st = intervals[0][0];
        int end = intervals[0][1];
        ArrayList<int[]> ans = new ArrayList<int[]>();
        for(int i=1;i<intervals.length;i++){
          if(end < intervals[i][0]){
            ans.add(new int[]{st,end});
            st = intervals[i][0];
            end = intervals[i][1];
          }
          else{
            end = Math.max(end , intervals[i][1]);
          }
        }

         ans.add(new int[]{st,end});
         int[][] ans1 = new int[ans.size()][2];
       for(int i=0;i<ans.size();i++){
        ans1[i][0] = ans.get(i)[0];
        ans1[i][1] = ans.get(i)[1];
       }
         return ans1;
    }
}