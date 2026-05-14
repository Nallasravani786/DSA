#### I M A G E
<img width="2856" height="1378" alt="image" src="https://github.com/user-attachments/assets/66d76e32-d43a-4b22-964b-daa4637321b3" />

#### I N T U I T I O N
First find the length of the linked list.

Middle node position is: len / 2

Traverse till the middle node while maintaining previous node.

Remove the middle node by skipping it: prev->next = middle->next

This changes links without creating a new list.

###### C O D E
```cpp
ListNode* deleteMiddle(ListNode* head) {
        ListNode*curr = head;
        int len = 0;

        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
        if(head== NULL || head->next == NULL) return NULL;

        ListNode*a = head;
        int cnt = 0;
        ListNode*prev = NULL;

        while(a!=NULL && cnt!=len/2){

            prev = a;
            a = a->next;
            cnt++;
        }
        prev->next = prev->next->next;

        return head;
    }
```
