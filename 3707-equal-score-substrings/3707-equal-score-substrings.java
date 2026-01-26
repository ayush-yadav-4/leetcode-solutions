class Solution {
    public boolean scoreBalance(String s) {
        int sum = 0;
        for(char ch:s.toCharArray()){
            sum+= ch-'a'+1;
        }
        int n = s.length();
        if(n<=1){
            return false;
        }
        int[] pre = new int[n];
        pre[0]=s.charAt(0)-'a'+1;

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + (s.charAt(i)-'a'+1);
        }

        for(int p:pre){
            if(p==sum-p){
                return true;
            }
        }

        return false;
    }
}