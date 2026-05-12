#### I M A G E
<img width="2849" height="1511" alt="image" src="https://github.com/user-attachments/assets/34610e75-4cf5-4b9e-83b1-24894c4dbc6c" />

#### I N T U I T I O N

Use two pointers: slow and fast.

slow moves one step, fast moves two steps.

If a cycle exists, fast pointer will eventually meet slow pointer.

If fast reaches NULL, the linked list has no cycle.

This is called Floyd’s Cycle Detection Algorithm

###### C O D E

```cpp
 bool hasCycle(ListNode *head) {
       ListNode*slow = head;
       ListNode*fast = head;

       while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
       } 
        return false;
    }

```
