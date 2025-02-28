class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int maxdiff = INT_MIN,minprice = INT_MAX;
        for(int price:prices){
             minprice = min(price,minprice);
             maxdiff = max(maxdiff,price-minprice);
        }
        return maxdiff;
    }
};