class Solution {
    public boolean lemonadeChange(int[] bills) {
        int cnt5=0,cnt10=0,cnt20=0;
        for(int i=0;i<bills.length;i++){
             if(bills[i] == 5){
                cnt5++;
             }
             else if(bills[i] == 10){
               if(cnt5<1)return false;
               cnt5--;
               cnt10++;
             }
             else if(bills[i] == 20){
                if(cnt10 >= 1 && cnt5 >=1){
                    cnt5--;
                    cnt10--;
                    cnt20++;
                }
                else if(cnt5>=3){
                    cnt5 -= 3;
                    cnt20++;
                }
                else return false;
             }
        }
        return true;
    }
}