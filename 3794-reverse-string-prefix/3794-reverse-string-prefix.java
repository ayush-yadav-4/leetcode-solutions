class Solution {
    public String reversePrefix(String s, int k) {
        
    StringBuilder str = new StringBuilder();
    for(int i=0;i<k;i++){
      str.append(s.charAt(i));
    }
    str.reverse();

    for(int i=k;i<s.length();i++){
      str.append(s.charAt(i));
    }
    return str.toString();
    }
}