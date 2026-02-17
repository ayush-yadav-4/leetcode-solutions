class Solution {
    public int prefixConnected(String[] words, int k) {
              Map<String, Integer> map = new HashMap<>();

        for(String w : words){
            if(w.length() < k) continue;

            String prefix = w.substring(0, k);
            map.put(prefix, map.getOrDefault(prefix, 0) + 1);
        }

        int ans = 0;

        for(int val : map.values()){
            if(val >= 2) ans++;
        }

        return ans;
    }
}