class Solution {
    int vow(String str){
      int cnt1 = 0;
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cnt1++;
        }
        return cnt1;
    }
    public String reverseWords(String s) {
        String[] arr = s.split(" ");
        int cnt = vow(arr[0]);
         StringBuilder ans = new StringBuilder(arr[0]);
        for(int i =1;i<arr.length;i++){
            int cnt2 = vow(arr[i]);
            if(cnt == cnt2){
                StringBuilder st = new StringBuilder(arr[i]).reverse();
                arr[i] = st.toString();
            }
          
                ans.append(" ");
                ans.append(arr[i]);
            
        }

        return ans.toString();
    }
}