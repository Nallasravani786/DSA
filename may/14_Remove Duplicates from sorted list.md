#### I M A G E
<img width="2826" height="1405" alt="image" src="https://github.com/user-attachments/assets/9d5451d4-e73c-47b1-a17d-ed6ff6773a9d" />

#### I N T U I T I O N

Since the list is sorted, duplicates appear consecutively.

Traverse the linked list once.

If current node and next node have same value:

skip the duplicate node by changing pointers.

Otherwise move to next node.

This removes duplicates without using extra space.

###### C O D E

```cpp
ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr = head;

        while(curr!=NULL && curr->next!=NULL){

            if(curr->val == curr->next->val) curr->next = curr->next->next;

            else curr = curr->next;
        }
        return head;
    }

```

