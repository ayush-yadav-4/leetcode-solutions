class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int start =0,end=0,ans =0,mid,total_time = 0;
         long long sum =0;
         
        for(int i = 0; i < piles.size(); i++){
            sum += piles[i];
            end = max(end , piles[i]);
        }
        
      start = sum/h;
      if(!start){ start = 1;}
        while(start<=end){
            mid = start + (end-start)/2;
            total_time =0;
            for(int i =0; i < piles.size(); i++){
               
              total_time += piles[i]/mid;
              if(piles[i]%mid){
                total_time++;
              }
            }

            if(total_time > h){
               start = mid+1;
            }
            else{
                ans = mid;
                end = mid-1;
            }
        }

        return ans;
    }                                       
};