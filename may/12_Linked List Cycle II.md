#### I M A G E
<img width="2850" height="1395" alt="image" src="https://github.com/user-attachments/assets/11a67932-6758-44c1-b69e-2182f3d0c025" />

#### I N T U I T I O N
Use slow and fast pointers to check whether a cycle exists.

Slow moves 1 step, fast moves 2 steps.

If both pointers meet, cycle is present.

Start another pointer from head.

Move both pointers one step at a time.

The node where they meet again is the starting node of the cycle.

###### C O D E 
```cpp

ListNode *detectCycle(ListNode *head) {
        ListNode*slow = head;
        ListNode*fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode*entry = head;

                while(entry!=slow){
                    entry = entry->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
    ```
