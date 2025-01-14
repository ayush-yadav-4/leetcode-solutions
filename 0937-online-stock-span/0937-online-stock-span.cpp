class StockSpanner {
public:
    stack<pair<int,int>>st;
     vector<int>arr;
    int idx =0;
    StockSpanner() {
       idx = -1;
       arr.push_back((int)NULL);
    }
    
    int next(int price) {
        idx++;
        int ans;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(!st.empty()){ 
            ans = idx - st.top().second;
       }
        else { ans = idx - (-1);
          }

        st.push({price,idx});


        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */