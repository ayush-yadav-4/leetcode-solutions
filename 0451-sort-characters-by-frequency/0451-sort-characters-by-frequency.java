class Solution {
   
    public String frequencySort(String s) {
        Map<Character , Integer>mp = new HashMap<>();

        for(int i=0;i<s.length();i++){
          mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i),0) + 1);

        }
        ArrayList<int[]> ls = new ArrayList<>();
        for(Map.Entry<Character , Integer> m : mp.entrySet()){
            ls.add(new int[]{m.getKey() - 'a', m.getValue()});
        }
        Collections.sort(ls, (a,b)->b[1] - a[1]);
        StringBuilder ans = new StringBuilder();

        for(int i=0;i<ls.size();i++){
            int n = mp.get((char)('a' + ls.get(i)[0]));

            for(int k=0;k<n;k++){
             ans.append((char)('a' + ls.get(i)[0]));
            }
           
        }
        return ans.toString();

    }
}