#### I M A G E 

<img width="2847" height="1470" alt="image" src="https://github.com/user-attachments/assets/c12c3e51-30cb-414a-a9c2-f8ff644e9cb9" />

#### I N T U I T I O N 

First, find the length n of the linked list

Reduce rotations using k = k % n (to avoid extra work)

Connect the last node to head → make the list circular

The new tail will be at position (n - k)

The node next to new tail becomes the new head

Break the link at new tail to get the rotated list

👉 One line memory:
“Make it circular → move (n - k) → break” 🚀

```cpp
 ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        // to find length
        int n =1;
        ListNode*tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }
        // reduce k
        k = k%n;
        if(k==0) return head;
        // make it circular
        tail->next = head;

        //to find neww tail
        int steps = n-k;
        ListNode*newtail = head;
        for(int i=1;i<steps;i++){
            newtail = newtail->next;
        }
        //break and form new head
        ListNode*newhead = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
```
