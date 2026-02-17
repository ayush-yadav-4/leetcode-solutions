class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        Map<Integer, Character> mp = new HashMap<>();

        for(int i=0 , c = 'z';i<26 && c>='a';i++,c--){
           mp.put(i,(char)c);
        }
        int idx = 0, sum=0;
       StringBuilder ans = new StringBuilder();
        for(String s : words){
            sum = 0;
            for(int i=0;i<s.length();i++){
                sum += weights[s.charAt(i)-'a'];
            }
            int num = (sum % 26);
            ans.append(mp.get(num));
        }

        return ans.toString();
    }
}