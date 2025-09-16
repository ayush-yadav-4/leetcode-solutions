class Solution {
    public String simplifyPath(String path) {
        Stack<String>st = new Stack<>();
        String[] arrs = path.split("/");

        for(String arr : arrs){
           if(arr.equals("") || arr.equals(".") || arr.equals("/")) {continue;}
           else if(arr.equals("..")){
              if(!st.empty()){
                st.pop();
              }
           }
           else{
             st.push(arr);
           }
           
        }
        StringBuilder ans = new StringBuilder("");
        for(String str : st){
           ans.append("/").append(str);
        }
        //ans.reverse();
        
        String ans1 = ans.toString();
        if(ans1.length() == 0) return "/";
        return ans1;

    }
}