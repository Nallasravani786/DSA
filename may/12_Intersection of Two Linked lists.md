#### I M A G E
<img width="2819" height="1202" alt="image" src="https://github.com/user-attachments/assets/a3769a87-98c4-43de-b8a2-3fbcf434bd1c" />

#### I N T U I T I O N 

Start two pointers from heads of both linked lists.

When a pointer reaches the end, move it to the head of the other list.

This makes both pointers travel equal total distance.

If an intersection exists, both pointers meet at that node.

If no intersection exists, both pointers finally become NULL

###### C O D E 

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a = headA;
        ListNode*b = headB;

        while(a!=b){
            if(a == NULL) a = headB;
            else a = a->next;
            if(b == NULL) b = headA;
            else b = b->next;
        }
        return a;
    }

```
