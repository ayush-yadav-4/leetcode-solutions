class Solution {
public:
    string addStrings(string num1, string num2) {
    //     if(num1.size() > num2.size()){
    //         return add(num1,num2);
    //     }
    //     else{
    //         return add(num2,num1);
    //     }
      
    // }

    // string add(string num1,string num2){

    //     int carry =0, idx1 = num1.size()-1, idx2 = num2.size()-1,sum=0;
    //     string ans;
    //       while(idx2 >= 0){
    //       sum = (num1[idx1] - '0') + (num2[idx2] - '0') + carry;
    //       carry = sum/10;
    //       char c =  '0' +(sum%10 );
    //       ans += c;
    //       idx1--; idx2--;
    //     }

    //      while(idx1 >= 0){
    //       sum = (num1[idx1] - '0') + carry;
    //       carry = sum/10;
    //      char c =  '0' +(sum%10 );
    //       ans += c;
    //        idx1--;
    //     }
    //     if(carry) ans += '1';

    //     reverse(ans.begin(), ans.end());

    //     return ans;

     int i = num1.size()-1,j=num2.size()-1,carry=0,sum=0;
        string ans;
        while(i>=0 && j>=0){
           sum = (num1[i]-'0' + num2[j] - '0' + carry);
           carry = sum/10;
           ans += to_string(sum%10);
           i--;j--;
        } 
        while(j>=0){
            sum = (num2[j] - '0' + carry);
           carry = sum/10;
           ans += to_string(sum%10);
           j--;
        }
        while(i>=0){
            sum = (num1[i] - '0' + carry);
           carry = sum/10;
           ans += to_string(sum%10);
           i--;
        }
        if(carry != 0){ ans += to_string(carry);}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};