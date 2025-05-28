// class StockSpanner {
// public:
//     stack<pair<int,int>>st;
//      vector<int>arr;
//     int idx =0;
//     StockSpanner() {
//        idx = -1;
//        arr.push_back((int)NULL);
//     }
    
//     int next(int price) {
//         idx++;
//         int ans;
//         while(!st.empty() && st.top().first<=price){
//             st.pop();
//         }
//         if(!st.empty()){ 
//             ans = idx - st.top().second;
//        }
//         else { ans = idx - (-1);
//           }

//         st.push({price,idx});


//         return ans;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */

class StockSpanner {
public:
   stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        if(this->st.empty()){
            this->st.push({price,1});
            return 1;
        }
        else{
            int idx = 0;
            while(!this->st.empty() && this->st.top().first <= price){
                idx += this->st.top().second;
                this->st.pop();
            }
            this->st.push({price,idx+1});
            return idx +1;

        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */