class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        long long ch5=0,ch10=0,ch20=0;

        for(int i=0;i<bills.size();i++){
        if(bills[i] == 5){
            ch5++;
        }
        else if(bills[i] == 10){
            if(ch5<1) return false;
            ch5--; ch10++;
        }
         else if(bills[i] == 20){
         if(ch5 >=1 && ch10>=1){ch10--;ch5--;ch20++; }
            else if(ch5>=3){ch5 = ch5-3; ch20++;}
           
            else return false;
            
        }
        }
        return true;
       
    }
};