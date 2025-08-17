class Solution {
    public String frequencySort(String s) {
         Map<Character, Integer> mp = new HashMap<>();
         for(char c : s.toCharArray()){
             mp.put(c,mp.getOrDefault(c,0) + 1);
         }

         List<Map.Entry<Character,Integer>>ls = new ArrayList<>(mp.entrySet());

         ls.sort((a,b) -> b.getValue() - a.getValue());
    StringBuilder ans = new StringBuilder();
         for(int i=0;i<ls.size();i++){
              char c = ls.get(i).getKey();
              int freq = ls.get(i).getValue();
              for(int j = 1;j<=freq;j++){
                 ans.append(c);
              }
         }
         return ans.toString();

    }
}