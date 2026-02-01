class Solution {

    boolean check(int num){
      StringBuilder str = new StringBuilder();

     while(num!=0){
        str.append(num%2);
        num = num/2;
     }

     for(int i=1;i<str.length();i++){
        if(str.charAt(i)!= str.charAt(i-1)) return false;
     }

     return true;

    }
    public int countMonobit(int n) {
         int cnt = 0;
        for(int i=0;i<=n;i++){
            if(check(i))cnt++;
        }

        return cnt;
    }
}