class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!= t.length()) return false;
        int[] cnt = new int[256];
        for(int i=0;i<s.length();i++){
         cnt[s.charAt(i)]++;
        }
        for(int i=0;i<s.length();i++){
         if( cnt[t.charAt(i)] == 0) return false;
         cnt[t.charAt(i)]--;
        }

        for(int i=0;i<256;i++){
          if(cnt[i] < 0 || cnt[i] > 0) return false;
        }
        return true;

    }
}