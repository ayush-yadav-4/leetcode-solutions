class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      if(stones.size() == 1) return stones[0];
       priority_queue<int>pq;
       for(int i=0;i<stones.size();i++){
          pq.push(stones[i]);
       }

       do{
         int stone = pq.top();
         pq.pop();
         stone -= pq.top();
         pq.pop();
          pq.push(stone);
       }while(pq.size()>1);
       return pq.top();
    }
};