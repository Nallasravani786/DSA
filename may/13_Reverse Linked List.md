#### I M A G E
<img width="2831" height="1331" alt="image" src="https://github.com/user-attachments/assets/116c5bf2-7948-497f-9661-1ce86ed07c9a" />

#### I N T U I T I O N

Traverse the linked list node by node.

For each node:

save the next node first

reverse the current node’s pointer

Maintain:

prev → already reversed part

curr → current node being processed

After reversing:

move prev forward

move curr to saved next node

When traversal ends:

prev points to the new head of reversed list.

###### C O D E

```cpp
ListNode* reverseList(ListNode* head) {
       ListNode*prev = NULL;
       ListNode*curr = head;

       while(curr!=NULL){
        ListNode*newnode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = newnode;
       } 
       return prev;
    }

```
