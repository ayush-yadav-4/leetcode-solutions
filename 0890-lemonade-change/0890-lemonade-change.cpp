class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change5 =0,change10=0,cut=0;
        for(int i=0; i<bills.size();i++){
           if(bills[i] == 5) change5 +=1;
           else if(bills[i] == 10) {
            if(change5 <=0) return false;
           else { change5--;
            change10++;}
           }
           else{
            if(change5 >0 && change10>0){
                 change10--; change5--;
            }
            else if(change5>=3) change5 -=3;
           
           else return false;
        }}
        return true;
    }
};