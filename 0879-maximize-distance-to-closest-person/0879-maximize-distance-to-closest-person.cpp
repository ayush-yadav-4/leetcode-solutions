class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    int prefix = -1,suffix = -1,zeros =0,maxzeroes =0;
      for(int i =0 ; i< seats.size(); i++){
         if(seats[i] == 0){
           zeros++;
         }
         else{
            if(prefix == -1){
                prefix = zeros;
            }
           else maxzeroes = max(maxzeroes,zeros);
            zeros = 0;
         }
      }

      suffix = zeros;
      return max(max(prefix,suffix),(maxzeroes+1)/2);
      
    }
};