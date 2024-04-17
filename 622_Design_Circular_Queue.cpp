class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        //check whether queue is full
        if( (front == 0 && rear == size-1) || ((rear+1) % size == front) ) {
            return false;
        }
        else if(front == -1) {
			front = rear = 0;  //first element to push
             
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;  //to maintain cyclic nature
        }
        else {
            rear++;   //normal flow
        }
        arr[rear] = value;  //push inside the queue
        return true;
    }
    
    bool deQueue() {
        //to check queue is empty
        if(front == -1){
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { 
            front = rear = -1;  //single element is present
        }
        else if(front == size - 1) {
            front = 0;  //to maintain cyclic nature
        }
        else
        {
            front++;  //normal flow
        }
        return true;
    }
    
    int Front() {
        if(front == -1)
            return -1;
        else 
            return arr[front];
    }
    
    int Rear() {
        if(front == -1)
            return -1;
        else 
            return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if( (front == 0 && rear == size-1) || ((rear+1) % size == front) ) 
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
