class Solution {
    public int[][] insert(int[][] ints, int[] newint) {
       List<int[]>ans = new ArrayList<>();
       int i=0,n = ints.length;
       while(i<n && ints[i][1] < newint[0]){
         ans.add(ints[i]);
         i++;
       }

       while(i<n && ints[i][0] <= newint[1]){
           newint[0] = Math.min(newint[0],ints[i][0]);
           newint[1] = Math.max(newint[1],ints[i][1]);
           i++;
       }
       ans.add(newint);

       while(i<n){
        ans.add(ints[i]);
         i++;
       }
       return ans.toArray(new int[ans.size()][]);
    }
}