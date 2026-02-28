class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans ="";
        String str = strs[0];
        for(int i=0;i<str.length();i++){
           String s = str.substring(0,i+1);
           int cnt =0;
           for(String st : strs){
             if(st.length() > i && s.equals(st.substring(0,i+1))){
               cnt++;
             }
             
           }
           if(cnt == strs.length){
            ans = s;
           }
           else break;
        }
        return ans;
    }
}