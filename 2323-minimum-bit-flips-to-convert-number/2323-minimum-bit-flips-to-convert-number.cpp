class Solution {
public:
    int minBitFlips(int start, int goal) {
       
        int flip=0;
        int ans = start ^ goal;
        while(ans != 0){
          if((ans&1) == 1) flip++;
          ans = ans>>1;
        }
        return flip;
    }
};