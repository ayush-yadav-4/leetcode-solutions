class Solution {
public:
    string frequencySort(string s) {
       vector<int>freq(128,0);
       for(char c:s){
        freq[c]++;
       }      
       auto cmp = [&](char a,char b){
        if(freq[a] == freq[b]) return a<b;
        return freq[a]>freq[b];
       };
       sort(s.begin(),s.end(),cmp);
      return s;
    
    }
};