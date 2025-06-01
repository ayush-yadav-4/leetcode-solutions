class Solution {
public:
    bool isPossible(vector<int>& target) {
        
       priority_queue<int>pq;
       long long int sum=0,remsum=0,elem=0,maxelem=0;
       for(int i=0;i<target.size();i++){
            pq.push(target[i]);
            sum += target[i];
       }

       while(pq.top() != 1){
         maxelem = pq.top(); pq.pop();
         remsum = sum - maxelem; 
         if(remsum <= 0 || remsum >= maxelem) return false;

         elem = maxelem % remsum;
         if(elem == 0){
            if(remsum == 1) return true;
            else return false;
         }
         sum = remsum + elem;
         pq.push(elem);
       }

     return true;
    }
};