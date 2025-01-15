class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q; int ans =1,elem = 0;
        for(int i=0 ; i< tickets.size();i++){
            q.push(i);
        }

        while(!q.empty()){
           
            elem = q.front();
            tickets[elem] = tickets[elem]-1;
           
            if(tickets[k] == 0) return ans;
            if(tickets[elem] == 0) q.pop();
            else{
                q.push(elem);
                q.pop();
            }
              ans++;
        }
        return ans;
    }
};