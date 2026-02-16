class Solution {

    class Pair{
        String word;
        int freq;

        Pair(String word, int freq){
           this.word = word;
           this.freq = freq;
        }
    }
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<Pair> q = new LinkedList<>();
        Set<String> st = new HashSet<>();
        for(int i=0;i<wordList.size();i++){
           st.add(wordList.get(i));
        }
        q.add(new Pair(beginWord,1));
        st.remove(beginWord);
        while(q.size() > 0){
            Pair p = q.poll();
            String word = p.word;
            int freq = p.freq;
           if(word.equals(endWord) == true) return freq;
            char[] word_arr = word.toCharArray();
            for(int i=0;i<word.length();i++){
               for(char c = 'a';c<= 'z';c++){
                 word_arr[i] = c;
                 String str = new String(word_arr);
                 if(st.contains(str) == true){
                    st.remove(str);
                    q.add(new Pair(str, freq+1));
                    
                 }
               }
               word_arr = word.toCharArray();
            }
        }

        return 0;
    }
}