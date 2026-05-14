#### I M A G E

<img width="2848" height="1467" alt="image" src="https://github.com/user-attachments/assets/eb86ae66-4d55-4350-85f9-a1d5c1afe7b8" />

#### I N T U I T I O N 
Keep two pointers:

one for odd position nodes

one for even position nodes

Rearrange links so:

odd nodes connect only to odd nodes

even nodes connect only to even nodes

Store the head of even list separately.

Traverse the list by skipping alternate nodes.

At the end:

connect last odd node to starting even node list.


###### C O D E

```cpp
ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*odd = head;
        ListNode*even = head->next;

        ListNode*evenhead = even;

        while(even != NULL && even->next != NULL){

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenhead;

        return head;
    }


```

