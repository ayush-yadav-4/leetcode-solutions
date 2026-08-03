class Solution {
    boolean check(String s){
        int st= 0, end = s.length()-1;

        while(st<end){
            if(s.charAt(st) != s.charAt(end)) return false;
            st++;
            end--;
        }

        return true;
    }
    void help(int idx ,String s, List<List<String>> ans, List<String> temp){
        if(idx == s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=idx ;i<s.length();i++){
          if(check(s.substring(idx,i+1))){
            temp.add(s.substring(idx,i+1));
            help(i+1,s,ans,temp);
            temp.remove(temp.size()-1);
          }
         
        }
       return;
    }
    public List<List<String>> partition(String s) {
         List<List<String>> ans = new ArrayList<>();
       List<String> temp = new ArrayList<>();
       help(0,s,ans,temp);
       return ans;
    }
}