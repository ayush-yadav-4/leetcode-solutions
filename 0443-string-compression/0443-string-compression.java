class Solution {
    public int compress(char[] chars) {
        if (chars.length <= 1) return chars.length;

        List<Character> ls = new ArrayList<>();
        int i = 0;

        while (i < chars.length) {
            int idx = i;
            char c = chars[i];
            int cnt = 0;

            while (idx < chars.length && chars[idx] == c) {
                idx++;
                cnt++;
            }

            ls.add(c);
           if(cnt > 1){
            String count = String.valueOf(cnt);
            for (char digit : count.toCharArray()) {
                ls.add(digit);
            }}

            i = idx;
        }

        for (int k = 0; k < ls.size(); k++) {
            chars[k] = ls.get(k);
        }

        return ls.size();
    }
}
