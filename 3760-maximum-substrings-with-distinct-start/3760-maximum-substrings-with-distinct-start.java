class Solution {
    public int maxDistinct(String s) {
        Set<Character> st = new HashSet<>();

        for(int i=0;i<s.length();i++){
            if(!st.contains(s.charAt(i))){
                st.add(s.charAt(i));
            }
        }
        return st.size();
    }
}