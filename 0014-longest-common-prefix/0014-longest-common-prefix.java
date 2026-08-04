class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 1) return strs[0];
        String s = strs[0];

        for(int i = s.length()-1;i>=0;i--){
           String ss = s.substring(0,i+1);
           int cnt = 0;
           for(int j=0;j<strs.length;j++){
            if(i>=strs[j].length()) break;
             if( strs[j].substring(0, i + 1).equals(ss)){
                cnt++;
             }
           }
           if(cnt == strs.length) return ss;
        }
        return "";
    }
}