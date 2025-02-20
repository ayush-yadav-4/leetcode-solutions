class Solution {
public:
    int compress(vector<char>& chars) {
       int count=0,idx=0; char elem;

        for(int i=0;i<chars.size();i++){
            elem = chars[i];
            count = 0;
            while(i<chars.size() && chars[i] == elem){
              i++;count++;
            }
            if(count == 1) chars[idx++] = elem;
            else{
                chars[idx++] = elem;
               string no = to_string(count);
                for(char c: no){
                  chars[idx++] = c;
                }

            }
            i--;
        }
        chars.resize(idx);
        return chars.size();

    }
};