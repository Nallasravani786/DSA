#### I M A G E
<img width="2849" height="1444" alt="image" src="https://github.com/user-attachments/assets/ed1fbe66-2bce-414f-8290-952786282269" />

#### I N T U I T I O N

Traverse both linked lists simultaneously from left to right.

At each step add:

node value from first list

node value from second list

carry from previous addition

Store:  sum % 10 as current digit.

Store: sum / 10 as carry for next step.

Create a new linked list to store the result.

Continue until both lists and carry are completely processed.

###### C O D E
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*dummy = new ListNode(0);
        ListNode*temp = dummy;
        int carry = 0;

        while(l1!=NULL || l2!=NULL || carry) {

            int sum = carry;

            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum/10;

            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }
        return dummy->next;
    }

```

