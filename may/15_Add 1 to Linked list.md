#### I M A G E

<img width="2854" height="1422" alt="image" src="https://github.com/user-attachments/assets/182c1356-584e-4fff-b1c8-056a6abae3dd" />

#### I N T U I T I O N

Adding 1 starts from the last digit, but singly linked list cannot move backward.

So first reverse the linked list to access digits from right to left.

Add carry (1) to nodes one by one:

if value becomes 10, make it 0 and continue carry

otherwise stop carry propagation

If carry still remains after last node:

create a new node with value 1

Finally reverse the list again to restore original order.


###### C O D E

  ```cpp
  Node*reverse(Node*head){
     Node*prev = NULL;
     Node*curr = head;
     
     while(curr!=NULL){
         
         Node*nextnew = curr->next;
         curr->next = prev;
         
         prev = curr;
         curr = nextnew;
     }
     return prev;
 } 
  
 
  
    Node* addOne(Node* head) {
        
     Node*rev = reverse(head);
     
     Node*curr = rev;
     int carry =1;
     
     while(curr!=NULL && carry){
         curr->data = curr->data +1;
         
         
         if(curr->data == 10){
             curr->data = 0;
             carry = 1;
         }
         else carry = 0;
         
         
         if(curr->next == NULL && carry == 1){
             
             curr->next = new Node(1);
             carry = 0;
         }
         
         curr = curr->next;
         
     }
     return reverse(rev);
    }


  ```

