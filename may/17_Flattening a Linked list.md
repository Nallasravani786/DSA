#### I M A G E

<img width="2832" height="1366" alt="image" src="https://github.com/user-attachments/assets/7ebc94a6-b37c-4fbb-8d8c-54b2b7f79253" />

#### I N T U I T I O N
Every vertical (bottom) linked list is already sorted.

Flatten the linked list from right to left recursively.

After flattening the right side:

merge current bottom list with flattened right list.

Merging is similar to merging two sorted linked lists.

Use only bottom pointers in the final flattened list.

###### C O D E

```cpp
Node*merge(Node*a,Node*b){
     
     Node*temp = new Node(-1);
     
     Node*dummy = temp;
     
     while(a!=NULL && b!=NULL){
         if(a->data < b->data) {
             temp->bottom = a;
             a = a->bottom;
         }
         else {
             temp->bottom = b;
             b = b->bottom;
         }
         temp = temp->bottom;
     }
     
     if(a!=NULL) temp->bottom = a;
     if(b!=NULL) temp->bottom = b;
     
     return dummy->bottom;
 }
  
    Node *flatten(Node *root) {
       
       if(root == NULL || root->next == NULL) return root;
       
       root->next = flatten(root->next);
       
       root = merge(root,root->next);
       return root;
        
    }
```

