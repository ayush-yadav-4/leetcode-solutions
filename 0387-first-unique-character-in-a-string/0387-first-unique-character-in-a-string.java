class Solution {
    public int firstUniqChar(String s) {
        LinkedHashMap<Character,Integer>mp = new LinkedHashMap<>(); 
        for(int i=0;i<s.length();i++){
           if(mp.containsKey(s.charAt(i))){
              mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0) + 1);
           }
           else mp.put(s.charAt(i),1);
        }

        for(Map.Entry<Character,Integer> m : mp.entrySet()){
            if(m.getValue() == 1) return s.indexOf(m.getKey());
        }
        return -1;

    }
}