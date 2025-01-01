class Solution {
public:
bool check(vector<int>&visited , string str){

    vector<int>self(27,0);
    for(int i =0; i <str.size();i++){
    if(self[str[i]-'a'] == 1) return false;
    self[str[i]-'a'] = 1;
    }
  

    for(int i =0; i <str.size();i++){
    if(visited[str[i]-'a'] == 1) return false;

    }
      return true;

}
  int help(vector<string>& arr,vector<int>&visited,int idx,int len){

   if(idx == arr.size()){
    return len;
   }
  string str = arr[idx];
   if(check(visited,str) == false){
   return help(arr,visited,idx+1,len);
   }
  else{
    for(int i =0; i <str.size();i++){
    visited[str[i]-'a'] = 1;
    }
    len += str.size();
    int op1 = help(arr,visited,idx+1,len);
    for(int i =0; i <str.size();i++){
    visited[str[i]-'a'] = 0;
    }

    len -= str.size();
    int op2 = help(arr,visited,idx+1,len);
 
    return max(op1,op2);
  }
  }
    int maxLength(vector<string>& arr) {
      int len =0;vector<int>visited(27,0);
      return help(arr,visited,0,len);
    }
};