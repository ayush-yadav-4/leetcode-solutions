class Solution {
    
    public String removeDuplicateLetters(String s) {
        Stack<Character> st = new Stack<>();
        int[] freq = new int[26];
        boolean[] used = new boolean[26];
        Arrays.fill(freq,0);
        for(int i=0;i<s.length();i++){
           freq[s.charAt(i)-'a']++;
        }

        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            freq[c-'a']--;
            if(used[c - 'a'] == true)continue;
            
            while(st.size() > 0 && st.peek() > c && freq[st.peek() - 'a'] > 0){
                char ch = st.pop();
                used[ch-'a'] = false;
            }

            st.add(c);
            used[c-'a'] = true;
        }
        StringBuilder ans = new StringBuilder();
        while(st.size() > 0){
            ans.append(st.pop());
        }
        return ans.reverse().toString();

    }
}