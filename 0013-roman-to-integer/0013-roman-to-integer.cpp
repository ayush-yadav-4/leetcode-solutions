class Solution {
public:
    int romanToInt(string s) {
        // map<char,int>mp;
        // mp['I'] = 1;
        //  mp['V'] = 5;
        //   mp['X'] = 10;
        //    mp['L'] = 50;
        //    mp['C'] = 100; 
        //    mp['D'] = 500;
        //    mp['M'] = 1000;
         
        //   string temp;       
        //   int ans=0,i=0;
        //   for(int i=0;i<s.size()-1;i++){
        //    if(mp[s[i]] < mp[s[i+1]]){
        //     ans -= mp[s[i]];
        //    }
        //    else   ans += mp[s[i]];
        //    } 
        //    ans += mp[s[s.size()-1]];
        //    return ans;

         int ans = 0;
         for(int i=0;i<s.size();i++){
            
            char curr = s[i],next = ' ';
            if(i+1 < s.size()){
                next = s[i+1];
            }

            switch(curr){
                case('I'):
                  if(next == 'V'){
                    ans +=4;
                    i++;
                  }
                  else if(next == 'X'){
                    ans += 9;
                    i++;
                  }
                  else {
                    ans+=1;
                  }
                  break;
                case('X'):
                  if(next == 'L'){
                    ans +=40;
                    i++;
                  }
                  else if(next == 'C'){
                    ans += 90;
                    i++;
                  }
                  else {
                    ans+=10;
                  }
                  break;
                case('C'):
                  if(next == 'D'){
                    ans +=400;
                    i++;
                  }
                  else if(next == 'M'){
                    ans += 900;
                    i++;
                  }
                  else {
                    ans+=100;
                  }
                  break;
                case('V'):
                  ans+=5;
                  break;
                case('L'):
                  ans+=50;
                  break;
                case('D'):
                  ans+=500;
                  break; 
                case('M'):
                  ans+=1000;
                  break;     
            }

         }

         return ans;
    }
};