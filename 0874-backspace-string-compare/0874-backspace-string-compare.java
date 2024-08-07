class Solution {
    public boolean backspaceCompare(String s, String t) {
        
        Stack<Character> st = new Stack<>();
        Stack<Character> st1 = new Stack<>();
        int i =0, j=0;
        while(i != s.length()){ 

            char a  = s.charAt(i);
            if(a == '#'){
            if(!st.isEmpty()){
                st.pop();
             
            }
           
             
            }else{
                st.push(a);
           
            }
            i++;
        }
         while(j !=t.length()){
             char b  = t.charAt(j);

             if(b == '#'){
            if(!st1.isEmpty()){
                st1.pop();

            }
         
            }else{
                st1.push(b);
              
            }
            j++;
         }


        
        String a ="",b = "";
        while(!st.isEmpty()){
            a = a+ st.pop();
            
           
        }
          while(!st1.isEmpty()){
            b =b+ st1.pop();
           
            
        }

        if(a.equals(b)) return true;
        else return false;
    }
}