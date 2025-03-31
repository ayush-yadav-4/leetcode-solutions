class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<long long int>pq;
        long long  int total=0,sum,remsum,maxelem,elem;
         for(int i=0;i<target.size();i++){
           pq.push(target[i]);
          
           total += target[i];
         }
        while(pq.top() != 1){
         maxelem = pq.top();
         pq.pop();

          remsum = total - maxelem;
            
            if(remsum >= maxelem || remsum <= 0) return 0;
                elem = maxelem % remsum;
                if(elem == 0){
                    if(remsum != 1) return 0;
                    else return 1;

                }
                
                total =  remsum + elem;
                 pq.push(elem);

          
        }
        return 1;
    }
};