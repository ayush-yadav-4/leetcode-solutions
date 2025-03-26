class MedianFinder {
    priority_queue<double>pq_max;
    priority_queue<double , vector<double>, greater<double>>pq_min;
public:
    MedianFinder() {
        
    }
    void Balance_Heap(){
         if(pq_max.size()-1 > pq_min.size()){
            pq_min.push(pq_max.top());
            pq_max.pop();
            }
            else if(pq_max.size() < pq_min.size()){
                pq_max.push(pq_min.top());
                pq_min.pop();
            }
    }
    
    void addNum(int num) {
        if(pq_max.size() == 0){
         pq_max.push(num);
        }else{

            if(num > pq_max.top()){
               pq_min.push(num);
              
           }
           else{pq_max.push(num);
             
           }
           Balance_Heap();
        }
    }
    
    double findMedian() {
          if(pq_max.size() == pq_min.size()){
                double sum = (pq_max.top() + pq_min.top())/2;
                return sum;
             }else{
              return pq_max.top();
            }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */