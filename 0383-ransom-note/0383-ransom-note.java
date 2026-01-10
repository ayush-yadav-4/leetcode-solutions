class Solution {
    public boolean canConstruct(String R, String M) {
       Map<Character,Integer> mp = new HashMap<>();

        for(int i =0;i<M.length();i++){
             if(mp.containsKey(M.charAt(i))){
                mp.put(M.charAt(i),mp.getOrDefault(M.charAt(i),0) + 1);
             }
             else mp.put(M.charAt(i),1);
        }
        
          for(int i =0;i<R.length();i++){
              if(mp.containsKey(R.charAt(i))){
                mp.put(R.charAt(i),mp.get(R.charAt(i)) - 1);
                if(mp.get(R.charAt(i)) == 0) mp.remove(R.charAt(i));
              }
              else return false;
          }

    return true;

    }
}