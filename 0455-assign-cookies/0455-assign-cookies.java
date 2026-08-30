class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
         int cnt = 0, idx = 0;
        for(int i=0;i<g.length;i++){
           while(idx < s.length && g[i]>s[idx])idx++;
           
          
           if(idx == s.length)break;
            if(g[i]<=s[idx]){cnt++; idx++;}
        }
        return cnt;
    }
}