class Solution {
 
public:

   bool check(string str){
    string str2 = str;
    reverse(str2.begin(),str2.end());
    if(str == str2){
        return true;
    }
    return false;
    }
    void help(vector<vector<string>>& ans, vector<string>& temp,string str){
       if(str.size() == 0){
        ans.push_back(temp);
        return;
       }

      for(int i=0; i<str.size();i++){
         
         string s = str.substr(0,i+1);
         if(check(s)){
           temp.push_back(s);
           help(ans,temp,str.substr(i+1));
           temp.pop_back();
         }
      }


    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans; vector<string> temp;
        help(ans,temp,s);
        return ans;
    }
};