class Solution {
    public int minLengthAfterRemovals(String s) {
        int[] freq = new int[2];
        for(int i = 0;i<s.length();i++){
            char a = s.charAt(i);
             freq[a-'a']++;
        } 

        return Math.abs(freq[0] - freq[1]);
    }
}