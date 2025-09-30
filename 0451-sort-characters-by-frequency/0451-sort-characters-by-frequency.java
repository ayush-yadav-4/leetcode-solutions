class Solution {
   
    public String frequencySort(String s) {
        Map<Character,Integer>mp = new HashMap<>();

        for(int i=0;i<s.length();i++){
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
        }

        List<Character> ls = new ArrayList<>(mp.keySet());

        Collections.sort(ls,(a,b)->{
            int freqa = mp.get(a);
            int freqb = mp.get(b);

            return freqb - freqa;
        });

        StringBuilder ans = new StringBuilder("");

        for(int i=0;i<ls.size();i++){
           for(int j = 0;j<mp.get(ls.get(i));j++){
            ans.append(ls.get(i));
           }
    }
    return ans.toString();
    }
}