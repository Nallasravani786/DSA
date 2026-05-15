#### I M A G E
<img width="2842" height="1318" alt="image" src="https://github.com/user-attachments/assets/4fd3c9e4-13d4-495f-8996-c4d0f405ce9b" />

#### I N T U I T I O N
Intuition for “Merge Two Sorted Linked Lists”

Both linked lists are already sorted.

So at every step:

the smaller front node should come first in answer.

Compare current nodes of both lists:

attach smaller node to result

move that list forward

Repeat until one list finishes.

Finally attach remaining nodes of the other list.

###### C O D E
```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*temp = new ListNode(-1);
        ListNode*dummy = temp;

        while(list1!=NULL && list2!=NULL){

            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }

            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

            if(list1!=NULL)   temp->next = list1;
            if(list2!=NULL) temp->next = list2;
            
            return dummy->next;
    }

```

