class Solution {
    public boolean isFascinating(int n) {
        String str=""+n+(n*2)+(n*3);
        if(str.length()!=9) return false;
        Map<Character,Integer>map=new HashMap<>();
        for(char ch:str.toCharArray()){
            if(ch=='0'){ 
              return false;
            }
            map.put(ch,map.getOrDefault(ch,0)+1);
            if(map.get(ch)>1){
                return false;
            }
        }
        for(char ch='1';ch<='9';ch++){
            if(!map.containsKey(ch)){
                return false;
            }
        }
        return true;
    }
}