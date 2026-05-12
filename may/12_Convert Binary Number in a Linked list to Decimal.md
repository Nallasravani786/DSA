####  I M A G E 
<img width="2838" height="1412" alt="image" src="https://github.com/user-attachments/assets/bdc1fe4b-2fdc-4c9a-a4ab-d22c70f20ef7" />

#### I N T U I T I O N

Traverse the linked list from left to right.

Current answer stores decimal value of bits processed so far.

Multiply answer by 2 to shift binary bits left.

Add current node value (0 or 1) as new last bit.

Continue until list ends.

###### C O D E
```cpp
 int getDecimalValue(ListNode* head) {
        int num =0;

        while(head) {
            num = num*2 + (head->val);
            head = head->next;
        }
        return num;
      
    }

```

