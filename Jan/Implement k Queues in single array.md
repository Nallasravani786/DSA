## I N T U T I O N
Single array is used to store k queues efficiently.

next[] acts like a linking system for both queue elements and free spaces.

freespot always points to the next available index in the array.

Enqueue takes a free index and links it to the queue’s rear.

Dequeue removes from front and returns the index back to free list.

```cpp
class kQueues {

    int n,k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
  public:
    
    kQueues(int n, int k) {
        
        this->n = n;
        this->k = k;
        
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        
        for(int i=0;i<n-1;i++){
            next[i]=i+1;
        }
        next[n-1] = -1;
        freespot =0;
            
    }

    void enqueue(int x, int i) {
        
        if(isFull()) return;
        
        int index = freespot;
        freespot = next[index];
        
        if(front[i] == -1){
            front[i] = index;
            
        } else {
            next[rear[i]] = index;
        }
        
        next[index] = -1;
        rear[i] = index;
        arr[index] = x;
    }

    int dequeue(int i) {
        
        
        if(isEmpty(i)) return -1;
        
        int index = front[i];
        front[i] = next[index];
        
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    bool isEmpty(int i) {
       
        return front[i] == -1;
    }

    bool isFull() {
        
        return freespot == -1;
    }
};
```
