#### I M A G E
<img width="2843" height="1376" alt="image" src="https://github.com/user-attachments/assets/a6c2372d-787c-49d2-b531-66636b6b793c" />

#### I N T U I T I O N
Count the number of:

0s,1s,2s in the linked list.

Traverse the list again.

Fill nodes: first all 0s then all 1s then all 2s

Since only node values are changed:

no extra linked list is needed

space complexity becomes O(1).

###### C O D E

```cpp
Node* segregate(Node* head) {
        
       
       Node*curr = head;
       
       int zeros = 0, ones = 0, twos = 0;
       
       while(curr!=NULL){
           
           if(curr->data == 0) zeros++;
           else if(curr->data == 1) ones++;
           else twos++;
           
           curr = curr->next;
       }
       
       curr = head;
       
       while(zeros){
         curr->data = 0;
         zeros--;
         curr = curr->next;
         
       }
      
       while(ones){
          curr->data = 1;
           ones--;
          curr = curr->next;
       }
       while(twos){
         curr->data = 2; 
           twos--;
           curr = curr->next;
       }
       return head;
    }

```
