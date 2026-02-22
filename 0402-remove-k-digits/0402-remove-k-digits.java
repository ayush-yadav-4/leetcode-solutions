class Solution {
    public String removeKdigits(String num, int k) {
        if(k == num.length() || k > num.length()) return "0";
        Stack<Character>st = new Stack<>();

        for(int i=0;i<num.length();i++){
          char c = num.charAt(i);
          if(st.size() == 0)st.add(c);
          else{
            while(st.size() > 0 && k > 0 && st.peek() > c){
                st.pop();
                k--;
            }
            st.add(c);
          }
        }
        while(k>0){
            st.pop();
            k--;
        }

        StringBuilder str = new StringBuilder();
        while(st.size() > 0){
            str.append(st.pop());
        }
        str = str.reverse();
        int i=0;
        boolean zero = false;
        while(i<str.length() && str.charAt(i) == '0'){
         i++;
         zero = true;
        }
       if(i == str.length()) return "0";
        return str.toString().substring(i,str.length());
    }
}