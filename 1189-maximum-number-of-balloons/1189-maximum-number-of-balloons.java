class Solution {
    public int maxNumberOfBalloons(String text) {
       Map<Character,Integer> mp = new HashMap<>();
       int ans = (int)1e7;
       for(int i=0;i<text.length();i++){
         if(mp.containsKey(text.charAt(i))){
             mp.put(text.charAt(i),mp.getOrDefault(text.charAt(i),0) +1);
         }
         else mp.put(text.charAt(i),1);
       } 
       String str = "balloon";
       for(int i=0;i<str.length();i++){
         if(!mp.containsKey(str.charAt(i))) return 0;
         else if(str.charAt(i) == 'l' || str.charAt(i) == 'o'){
            if(mp.get(str.charAt(i))<2) return 0;
         }
       }

       for(Map.Entry<Character,Integer> m : mp.entrySet()){
        char c = m.getKey();
           
           if(c == 'l'|| c == 'o' ){
            ans = Math.min(ans,(m.getValue()/2));
           }
          else if(c == 'a' || c == 'b' ||c == 'n'){
              ans = Math.min(ans,m.getValue());
           }
       }

       return ans;
    }
}