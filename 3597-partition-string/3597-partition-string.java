class Solution {
    public List<String> partitionString(String s) {
        List<String>ans = new ArrayList<>();

        Map<String,Integer>mp = new HashMap<>();
        StringBuilder str = new StringBuilder();
        for(int i=0;i<s.length();i++){
            str.append(s.charAt(i));
           if(mp.containsKey(str.toString()) == false){
            mp.put(str.toString(),1);
            ans.add(str.toString());
            str = new StringBuilder();
           }
           
        }
        return ans;
    }
}