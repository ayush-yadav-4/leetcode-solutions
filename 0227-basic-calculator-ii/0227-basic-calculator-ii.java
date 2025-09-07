class Solution {
    public int calculate(String s) {
        int ans = 0, i = 0, lastnum = 0;
        char op = '+';
        char[] chars = s.toCharArray();
        while(i < s.length()) {
            int cur = 0;
            while(i < s.length() && chars[i] == ' ') i++;
            while(i < s.length() && (chars[i] >= '0' && chars[i] <= '9')) {
                cur = (cur * 10) + (chars[i] - '0');
                i++;
            }
            
            if(op == '+') {
                ans += lastnum;
                lastnum = cur;
            }
            else if(op == '-') {
                ans += lastnum;
                lastnum = -cur;
            }
            else if( op == '*') lastnum *= cur;
            else lastnum /= cur;
            
            while(i < s.length() && chars[i] == ' ') i++;
            if(i < s.length()) op = chars[i++];
        }
        ans += lastnum;
        System.out.println(ans);
        return ans;
    }
}