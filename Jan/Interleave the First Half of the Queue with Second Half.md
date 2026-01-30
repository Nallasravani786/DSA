## I N T U T I O N  (BRUTE)
First, the queue is emptied into an array so we can access elements by index (queues don’t allow random access).

The array is split into two halves:

temp1 → first half of the queue

temp2 → second half of the queue

Now we interleave elements:

take one element from temp1

then one from temp2

repeat until all elements are used

Finally, the rearranged array is pushed back into the queue in order.

```cpp
void rearrangeQueue(queue<int> &q) {
        int n = q.size();
       vector<int>temp(n);
       int j=0;
       while(!q.empty()){
           temp[j++]= q.front();
           q.pop();
       }
      
        vector<int>temp1(n/2);
        vector<int>temp2(n/2);
        
        for(int i=0;i<n;i++){
          if(i<n/2) temp1[i]=temp[i];
          else temp2[abs(n/2-i)]=temp[i];
        }
        
        int i1=0,i2 =0;
        int k=0;
        while(k<n && i1<n/2 && i2<n/2){
            temp[k]=temp1[i1];
            k++;
            temp[k]=temp2[i2];
            //i++;
            i1++;
            i2++;
            k++;
        }
         
        for(int i=0;i<n;i++){
            q.push(temp[i]);
        }
   
    }

```
## I N T U I T I O N  (OPTIMAL)
Store first half of queue separately

Remaining elements stay as second half

Push one from first half, then one from second half alternately

```cpp
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        queue<int> firstHalf;

        // Step 1: move first half into another queue
        for(int i = 0; i < n/2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Step 2: interleave first half and second half
        while(!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
```




