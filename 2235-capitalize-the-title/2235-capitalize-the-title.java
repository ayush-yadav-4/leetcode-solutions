class Solution {
    public String capitalizeTitle(String title) {
         StringBuilder ans = new StringBuilder("");
         String[] arr = title.split(" ");
        for(String str : arr){
           
           if(str.length()<=2){
            ans.append(str.toLowerCase());
           }
           else{
            char First = Character.toUpperCase(str.charAt(0));
            String rest = str.substring(1,str.length());
            ans.append(First).append(rest.toLowerCase());
           }
           ans.append(" ");
        }

        return ans.toString().trim();
    }
}