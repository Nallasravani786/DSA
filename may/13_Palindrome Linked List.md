#### I M A G E
<img width="2843" height="1392" alt="image" src="https://github.com/user-attachments/assets/a11eb46c-613c-40bf-bb88-3c4573285b89" />

#### I N T U I T I O N
First find the length of the linked list.

Move to the middle of the list.

Reverse the second half of the linked list.

Now:

first half moves forward normally

second half moves in reversed order

Compare values of both halves node by node.

If all values match → linked list is palindrome.

###### C O D E 

```cpp
ListNode*Reverse(ListNode*head){
        ListNode*prev = NULL;
        ListNode*curr = head;

        while(curr!=NULL){
            ListNode*nextnode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextnode;

        }
        return prev;
    }

     bool isPalindrome(ListNode* head) {
        
        int len = 0;
        ListNode*a = head;
        while(a!=NULL){
            len++;
            a = a->next;
        }

        ListNode*s = head;
        int cnt =1;

        while(cnt <= len/2){
            s = s->next;
            cnt++;
        }

        s = Reverse(s);

        ListNode*check1 = head;
        ListNode*check2 = s;

        while(check1 !=NULL && check2 !=NULL){
            if(check1->val != check2->val) return false;
            check1 = check1->next;
            check2 = check2->next;
        }

            return true;
        }
```


