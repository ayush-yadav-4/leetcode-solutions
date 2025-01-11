class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1; stack<char>st2;
        int i=0;
        while(s[i] != '\0'){
            if(s[i] == '#'){
               if(!st1.empty()) st1.pop();
            }
            else st1.push(s[i]);
            i++;
        }
        i=0;
        while(t[i] != '\0'){
            if(t[i]  == '#'){
                if(!st2.empty()) st2.pop();
            }else st2.push(t[i]);
            i++;
        }
        if(st1.empty() && st2.empty()) return true;

        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()){ return false;}

            st1.pop(); st2.pop();
        }
        if((st1.empty() && !st2.empty()) || (!st1.empty() && st2.empty())) return false;
        return true;

    }
};