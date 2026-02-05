class Solution {
    public String processStr(String s) {
        StringBuilder str = new StringBuilder();

        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '*'){
              if(str.length() >= 1){
                  str = new StringBuilder(str.toString().substring(0,str.length()-1));
              }
            }
              else if(s.charAt(i) == '#'){
                str.append(str);
              }
              else if(s.charAt(i) == '%'){
                str = str.reverse();
              }
              else{
                str.append(s.charAt(i));
              }
            

        }
        return str.toString();

    }
}