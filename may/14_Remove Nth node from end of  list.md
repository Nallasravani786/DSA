
#### I M A G E
<img width="2849" height="1522" alt="image" src="https://github.com/user-attachments/assets/92c1c520-79ca-46f0-b6b8-2b11f69a1be1" />

#### I N T U I T I O N 

First calculate the length of the linked list.

The node to remove from start is: len - n

Traverse until the node just before the target node.

Change links to skip the target node: prev -> next = target -> next

This removes the nth node from the end without extra space.

######  C O D E

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len =0;
        ListNode*curr = head;
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }

        if(n == len) return head->next;
     
      ListNode*a = head;
      ListNode*prev = NULL;
      int cnt =0;

      while(a!=NULL && cnt!=len-n){
        prev = a;
        a = a->next;
        cnt++;
      }
     prev->next = prev->next->next;

     return head;
       
    }
```
