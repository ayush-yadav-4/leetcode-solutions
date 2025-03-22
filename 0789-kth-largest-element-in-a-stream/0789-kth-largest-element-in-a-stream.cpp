class KthLargest {
    const int comp = INT_MIN;
    int k=0;
    int smallest = comp;
    priority_queue<int , vector<int>,greater<int>>pq;
    vector<int>arr;
public:
    KthLargest(int k, vector<int>& nums) {
        this->arr = nums;
        this->k = k;
    }
    
    int add(int val) {
        if(this->smallest != comp){
           if(this->pq.top() < val){
            this->pq.pop();
            this->pq.push(val);
            return pq.top();
           }
        }
        else{
        this->arr.push_back(val);
        
       for(int i=0;i<k;i++){
         this->pq.push(this->arr[i]);
       }

         for(int i=k;i<this->arr.size();i++){
            if(this->arr[i] > this->pq.top()){
                this->pq.pop();
                this->pq.push(this->arr[i]);
            }
       }
       this->smallest = this->pq.top();
      
    }
     return this->pq.top();
    }
   
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */