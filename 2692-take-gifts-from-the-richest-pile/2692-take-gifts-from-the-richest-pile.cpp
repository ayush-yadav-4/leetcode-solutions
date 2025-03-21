class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long total =0;
        priority_queue<long long int >pq;
        for(int i=0;i<gifts.size();i++){
          pq.push(gifts[i]);    
        }
        while(k--){
          long long int elem = pq.top();
          pq.pop();
          
          pq.push((int)(sqrt(elem)));
        }
         while(!pq.empty()){
            total += pq.top(); pq.pop();
         }
        
        return total;

    }
};