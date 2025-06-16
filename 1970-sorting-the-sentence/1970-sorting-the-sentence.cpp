class Solution {
public:
    string sortSentence(string s) {
    //     vector<string>nums(10,"-1");
    //     int pos=0,start=0,i=0,last=0;
    //     string temp,ans;
    //     while(s[i]!= '\0'){
    //        if(s[i] == ' '){
    //         pos = temp[temp.size()-1] - '0';
    //      temp.pop_back();
    //         nums[pos] = temp;
    //         temp.clear();
    //         i++;
    //        }else{
    //         temp += s[i];
    //         i++;
    //        }
    //     }
    // // we'll not get space at last so , temp will have the last word in it 
    //      pos = temp[temp.size()-1] - '0';
    //       temp.pop_back();
    //         nums[pos] = temp;

    //     for(int i=1;i<nums.size();i++){
    //        if(nums[i] != "-1"){
    //         ans.append(nums[i]);
    //         ans.append(" ");
    //        }
        
    //     }
    //     ans.pop_back();
    //     return ans;

    map<int,string>mp;
    istringstream iss(s); string st,ans;
    while(iss >> st){
      mp[st[(int)st.size()-1]] = st.substr(0,st.size()-1);
    }

    for(auto it:mp){
      ans+= it.second;
      ans+=" ";
    }
    ans.pop_back();
    return ans;
    
    }
};