class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long int total =0;
        priority_queue<long long int >pq;
        for(int i=0;i<gifts.size();i++){
          pq.push(gifts[i]);   
          total += gifts[i];   
        }
        while(k--){
          long long int elem = pq.top();
          pq.pop();
          total -= (elem - (int)(sqrt(elem)));
          pq.push((int)(sqrt(elem)));
        }
        
        
        return total;

    }
};