#### I M A G E

<img width="2854" height="1512" alt="image" src="https://github.com/user-attachments/assets/ceca3800-9f86-4a58-b879-771b09552d4d" />

#### I N T U I T I O N
Linked lists are best sorted using Merge Sort because merging can be done efficiently using pointers.

Find the middle of the linked list using slow and fast pointers.

Split the list into two halves.

Recursively sort: left half  , right half

Merge the two sorted halves into one sorted linked list.

Repeat until the whole list becomes sorted.

###### C O D E
```cpp
 ListNode* merge(ListNode*a , ListNode*b){

    ListNode*temp = new ListNode(-1);
    ListNode*dummy = temp;

    while(a!=NULL && b!=NULL){
        if(a->val < b->val){
            temp->next = a;
            a = a->next;
        }
        else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }

    if(a!=NULL) temp->next = a;
    if(b!=NULL) temp->next = b;

    return dummy->next;
  }

    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;

        ListNode*slow = head;
        ListNode*fast = head->next;

        while(fast!=NULL && fast->next!=NULL) {

            slow = slow->next;
            fast = fast->next->next;

        }
            ListNode*right = slow->next;
            slow->next = NULL;
            ListNode*left = head;


            left = sortList(left);
            right = sortList(right);


            return merge(left,right);
    }
```
