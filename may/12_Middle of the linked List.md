#### I M A G E
<img width="2832" height="1335" alt="image" src="https://github.com/user-attachments/assets/ab799374-d24b-4da3-be4c-aec5939ad890" />

##### I N T U I T I O N

First traverse the linked list and count total number of nodes.

Middle node position will be length / 2.

Start again from head.

Move forward length / 2 times.

The node where pointer stops is the middle node

###### C O D E

```cpp
ListNode* middleNode(ListNode* head) {
       int len = 0;
       ListNode*a = head;
       while(a!= NULL){
         len++;
         a = a->next;
       } 

     int cnt = 0;
     ListNode*middle = head;
      
     while(cnt<len/2) {
                head = head->next;
                middle = head;
               cnt++;
            }
        
        return middle;
      }
```
