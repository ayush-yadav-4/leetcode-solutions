class Solution {
public:
void help( vector<string>&ans,string digits,unordered_map<char,string>&mp,int idx,string &temp){
   if(idx == digits.size()){
    ans.push_back(temp);
    return;
   }

 string str = mp[digits[idx]];
for(int j =0; j<str.size();j++){
   temp.push_back(str[j]);
   help(ans,digits,mp,idx+1,temp);
   temp.pop_back();
}
 
   
}
    vector<string> letterCombinations(string digits) {
       
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
       vector<string>ans; string temp;
          if(digits == ""){
            return ans;
        }
      help(ans,digits,mp,0,temp);
      return ans;



    }
};