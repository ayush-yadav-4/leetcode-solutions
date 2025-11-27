class Solution {
    int check(int[]freq){
        int cnt = 0;
        for(int i=0;i<freq.length;i++){
           if(freq[i] >= 1)cnt++;
        } 
        return cnt;
    }
    public int totalFruit(int[] fruits) {
        if(fruits.length == 1 || fruits.length == 2) return fruits.length;
        // int[] freq = new int[fruits.length+1];
        // Arrays.fill(freq,0);

        Map<Integer, Integer>mp = new HashMap<>();
        int ans = 0,st = 0, end = 0;
        while(end < fruits.length){
           mp.put(fruits[end], mp.getOrDefault(fruits[end],0) + 1);

           while(mp.size() > 2 && st <= end){
             mp.put(fruits[st],mp.get(fruits[st])-1);
             if(mp.get(fruits[st]) == 0){
                mp.remove(fruits[st]);
             }
             st++;
           }

           if(mp.size() <= 2) ans = Math.max(ans,end - st +1);
           end++;
        }

        return ans;
    }
}