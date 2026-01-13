class Solution {
    public int findMaxVal(int n, int[][] resu, int[] diff) {
        
        //int last = 0,ans = 0,num=0,res=0,maxval=0;
       int[] maxi = new int[n];
       Arrays.fill(maxi,Integer.MAX_VALUE);
       maxi[0] = 0;

       for(int[] r: resu){
           maxi[r[0]] = r[1];
       }

       for(int i =1;i<n;i++){
          maxi[i] = Math.min(maxi[i],maxi[i-1] + diff[i-1]);
       }

       for(int i =n-2;i>=0;i--){
          maxi[i] = Math.min(maxi[i],maxi[i+1] + diff[i]);
       }
           int ans =0;
       for(int a : maxi){
         ans = Math.max(a,ans);
       }
        return ans;
    }
}