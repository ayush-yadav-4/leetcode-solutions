class Solution {
public:
bool Freqsame(vector<int>&freq, vector<int>&winfreq){
  
  for(int i=0;i<freq.size();i++){
        if(freq[i] != winfreq[i]){
            return false;
        }
  }
  
  return true;
}
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0);   
        int winidx = 0, winsize = s1.size(), idx = 0;
        for(int i=0; i<s1.size();i++){
            freq[s1[i] - 'a']++;
        }

        for(int i=0; i< s2.size();i++){
            winidx = 0; winsize = s1.size(); idx = i;
            vector<int>winfreq(26,0);
            while(idx < s2.size() && winidx < winsize){
               winfreq[s2[idx] - 'a']++;
               winidx++; idx++;
            }
            if(Freqsame(freq,winfreq)) return true;


        }
        return false;
    }
};