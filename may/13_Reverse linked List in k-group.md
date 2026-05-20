#### I M A G E
<img width="2851" height="1423" alt="image" src="https://github.com/user-attachments/assets/7426e851-5cf1-4289-8f25-49c0ba3b84a8" />

#### I N T U I T I O N
Process the linked list in groups of size k.

Before reversing:

check whether k nodes are available.

if not available, keep remaining nodes unchanged.

Reverse current k nodes using normal linked list reversal.

After reversing:

current group’s old head becomes the tail.

Recursively reverse remaining list and attach it to current tail.

Return new head of reversed group

###### C O D E

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp = head;

        for(int i=0;i<k;i++){

            if(temp == NULL) return head;

            temp = temp->next;
        }

        int cnt =0;
        ListNode*prev = NULL;
        ListNode*curr = head;

        while(curr!=NULL  && cnt<k){

         ListNode*nextnode = curr->next;

         curr->next = prev;

         prev = curr;
         curr = nextnode;

         cnt++;
        }

         head->next = reverseKGroup(curr,k);
        return prev;
    }
```
