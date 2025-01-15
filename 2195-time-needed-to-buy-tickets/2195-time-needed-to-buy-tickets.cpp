class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q; int ans =1,elem = 0;
        for(int i=0 ; i< tickets.size();i++){
            q.push(i);
        }

        while(!q.empty()){
           
            tickets[q.front()]--;
            if(tickets[k] == 0) return ans;
            if(tickets[q.front()] != 0) q.push(q.front());
        
              q.pop();
              ans++;
        }
        return ans;
    }
};