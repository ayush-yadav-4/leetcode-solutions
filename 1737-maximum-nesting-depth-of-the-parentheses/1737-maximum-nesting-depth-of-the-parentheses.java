class Solution {
    public int maxDepth(String s) {
        int cnt =0,maxcnt = 0;
        for(int i=0;i<s.length();i++){
        if(s.charAt(i) == '('){
            cnt++;
            maxcnt = Math.max(maxcnt,cnt);
        }
        else if(s.charAt(i) == ')') cnt--;
        if(cnt<0) cnt = 0;
        }
        return maxcnt;
    }
}