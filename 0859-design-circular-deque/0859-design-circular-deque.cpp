class MyCircularDeque {
 int* arr; 
 int front,back,size;
public:
    MyCircularDeque(int k) {
        size = k;
    arr = new int[size];
    front = -1; back =-1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        if(front == -1 && back ==-1){
            front = 0;
            back =0;
            arr[front] = value; return true;
        }
        else{
            front = (front-1 + size)%size;
            arr[front] = value;
            return true;
        }



       
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        
        if(front == -1 && back ==-1){
            front = 0;
            back =0;
            arr[back] = value; return true;
        }
        else{
            back = (back+1)%size;
            arr[back] = value; return true;
        }
    }
    
    bool deleteFront() {
         if(isEmpty()) return false;
         if(front == back){
          front = -1; back = -1;
          return true; 
         }
         else{
            front = (front+1)%size;
            return true;
         }
           
    }
    
    bool deleteLast() {
           if(isEmpty()) return false;
         if(front == back){
          front = -1; back = -1;
          return true; 
         }
         else{ back = (back-1+size)%size;
         return true;}
    }
    
    int getFront() {
         if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        if(front == -1 && back ==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(((front - 1 + size)%size == back) || ((back+1)%size == front)) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */