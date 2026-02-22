class StockSpanner {
    List<Integer> arr = new ArrayList<>();
    public StockSpanner() {
        
    }
    
    public int next(int price) {
        int cnt = 0;
        arr.add(price);
        int i = arr.size()-1;
        while(i>=0 && arr.get(i) <= price){
            i--; cnt++;
        }
        return cnt;
        
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */